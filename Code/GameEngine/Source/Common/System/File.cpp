// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/System/File.cpp): only the placed
// ?lock@File, ?close@File, ?open@File, ??1File, ?size@File, ?position@File,
// ?print@File, ?eof@File and ?unlock@File bodies are defined here.
// Slots stay declared-only (destructor for the slot-0 delete-this dispatch,
// rest for layout) and the donor's other members stay out, so the
// unmatched-definition gate passes. Layout follows the donor: AsciiString is
// pointer-sized (+0x04), access +0x08, single-byte open/deleteOnClose flags,
// mutex handle +0x10; close is slot 2, open slot 1, lock slot 15, unlock
// slot 16. The member is a TU-local AsciiString whose inline set() reaches
// StringBase::set and whose forceinline dtor reaches the folded clear, so the
// open/close set calls and the destructor teardown stay direct. /O1: retail
// keeps its zero in ebx (cmp/mov bl + push ebx); default flags use immediates
// and drop a callee-saved save. Imports read straight out of retail: KERNEL32
// CreateMutexA + WaitForSingleObject + CloseHandle.

typedef void *FileHandle;

extern "C" __declspec(dllimport) FileHandle __stdcall CreateMutexA(void *attrs, int owned, const char *name);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(FileHandle handle, unsigned long timeout);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void *handle);
extern "C" __declspec(dllimport) int __stdcall ReleaseMutex(FileHandle handle);

typedef char *va_list;
#define va_start(ap, v) (ap = (va_list)&v + ((sizeof(v) + 3) & ~3))
#define va_end(ap) (ap = (va_list)0)
extern "C" __declspec(dllimport) int __cdecl vsprintf(char *buffer, const char *format, va_list args);

static const unsigned long FILE_INFINITE = 0xFFFFFFFF;

template <typename T>
class StringBase
{
public:
	void set(const T *str);
private:
	void *m_data;
};

class AsciiString
{
public:
	void set(const char *str) { m_base.set(str); }
	void clear();
	__forceinline ~AsciiString() { clear(); }
private:
	StringBase<char> m_base;
};

class File
{
public:
	virtual ~File();
	virtual bool open(const char *filename, int access);
	virtual void close();
	enum seekMode { START, CURRENT, END };
	enum { TEXT = 0x20 };

	virtual int read(void *buffer, int bytes);
	virtual int write(const void *buffer, int bytes);
	virtual int seek(int bytes, seekMode mode);
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual bool print(const char *format, ...);
	virtual int size();
	virtual int position();
	virtual void slot13();
	virtual void slot14();
	virtual void lock();
	virtual void unlock();

	bool eof();

protected:
	void setName(const char *name)
	{
		m_nameStr.set(name);
	}

private:
	AsciiString m_nameStr;
	int m_access;
	unsigned char m_isOpen;
	unsigned char m_deleteOnClose;
	unsigned char m_pad0E[2];
	FileHandle m_mutex;
};

void File::lock()
{
	if (m_mutex == 0)
		m_mutex = CreateMutexA(0, 1, 0);
	else
		WaitForSingleObject(m_mutex, FILE_INFINITE);
}

// ?unlock@File@@UAEXXZ
// Slot 16 of File's vtable (0x0087A808) and of every subclass that inherits
// it. BFME1 File::unlock verbatim (matched there at 0x009CB790, same 15 bytes):
// a File that was never locked has no mutex, hence the test.
void File::unlock()
{
	if (m_mutex != 0)
		ReleaseMutex(m_mutex);
}

// ?size@File@@UAEHXZ
// Slot 11 of File's vtable, inherited by LocalFile, RAMFile and
// StreamingArchiveFile. ZH / BFME1 File::size verbatim (BFME1 0x009CB670, 53B).
int File::size()
{
	int pos = seek(0, CURRENT);
	int size = seek(0, END);

	seek(pos, START);

	return size < 0 ? 0 : size;
}

// ?position@File@@UAEHXZ
// Slot 12. ZH / BFME1 File::position verbatim (BFME1 0x009CB6B0, 10B).
int File::position()
{
	return seek(0, CURRENT);
}

// ?print@File@@UAA_NPBDZZ
// Slot 10, inherited by every File subclass here. ZH / BFME1 File::print
// (BFME1 0x009CB6C0): 10K stack buffer, TEXT-mode check, vsprintf through the
// msvcr71 import, then write through slot 4.
bool File::print(const char *format, ...)
{
	char buffer[10*1024];
	int len;

	if (!(m_access & TEXT))
	{
		return false;
	}

	va_list args;
	va_start(args, format);
	len = vsprintf(buffer, format, args);
	va_end(args);

	if (len >= sizeof(buffer))
	{
		return false;
	}

	return (write(buffer, len) == len);
}

// ?eof@File@@QAE_NXZ
// ZH / BFME1 File::eof verbatim (BFME1 0x009CB740, same 30 bytes): position
// through slot 12 first, then size through slot 11.
bool File::eof()
{
	return position() == size();
}

// ?close@File@@UAEXXZ
// BFME1 File::close shape (their setName ends with deleteInstance; ours clears
// m_deleteOnClose first and then deletes through vtable slot 0 with a separate
// operator delete -- a plain delete this, not MemoryPoolObject's
// getObjectMemoryPool/dtor/freeBlock sequence). Retail calls the one-arg
// StringBase::set, so setName is the one-arg form here, not the two-arg +
// strlen spelling BFME1 uses.
void File::close()
{
	if (m_isOpen) {
		setName("<no file>");
		m_isOpen = 0;
		if (m_deleteOnClose) {
			m_deleteOnClose = 0;
			::delete this;
		}
	}
}

// ?open@File@@UAE_NPBDH@Z
// BFME1 File::open logic (their setName is the two-arg + strlen form; ours is
// the one-arg form like close, so no length push). Access-flag numbering is
// unchanged from Zero Hour (READ 1, WRITE 2, APPEND 4, TRUNCATE 0x10,
// TEXT 0x20, BINARY 0x40, STREAMING 0x100).
bool File::open(const char *filename, int access)
{
	if (m_isOpen) {
		return false;
	}
	setName(filename);
	if ((access & (0x100 | 0x02)) == (0x100 | 0x02)) {
		return false;
	}
	if ((access & (0x20 | 0x40)) == (0x20 | 0x40)) {
		return false;
	}
	if ((access & (0x01 | 0x02)) == 0) {
		access |= 0x01;
	}
	if (!(access & (0x01 | 0x04))) {
		access |= 0x10;
	}
	if ((access & (0x20 | 0x40)) == 0) {
		access |= 0x40;
	}
	m_access = access;
	m_isOpen = 1;
	return true;
}

// ??1File@@UAE@XZ
// BFME1 File::~File verbatim: clears delete-on-close (so a self-deleting File
// does not re-enter delete while being destroyed), closes, then releases the
// mutex. The trailing AsciiString teardown (0x36410 via the forceinline member
// dtor) is implicit.
File::~File()
{
	m_deleteOnClose = 0;
	close();
	if (m_mutex) {
		CloseHandle(m_mutex);
	}
}
