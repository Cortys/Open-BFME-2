// cl: /O1 /DNDEBUG /MD
//
// ?rva00098BD4@DirectInputKeyboard@@QAEXXZ, retail 0x00098BD4, 188 bytes.
// Slot-1 DirectInput creator for the 0xE28-byte keyboard input class: creates
// the DirectInput8 object plus the SysKeyboard device into +0xE20/+0xE24,
// then SetDataFormat/SetCooperativeLevel/SetProperty(BUFFER)/Acquire, with
// releaseDevices teardown on every FAILED path. Evidence: donor BFME1
// Win32DIKeyboard.cpp openKeyboard (same 5 FAILED checks, same DIPROPDWORD
// 0x14/0x10/0/0/0x100, same tail Acquire); neighbours 0x98B55 ctor (CapsLock)
// 0x98B8B dtor and 0x98A6F releaseDevices; W3DGameClient DirectInputKeyboard
// shape (Keyboard plus 8 tail bytes, BFME2 +4 to 0xE28).

extern void *ApplicationHInstance;
extern void *Rva00DDE024;
extern const unsigned char g_00CDF7E8[];
extern const unsigned char g_00CDF678[];
extern const unsigned char g_00C7C9A4[];

long __stdcall ji_0062af20(void *hinst, unsigned long ver, const void *riid, void **ppv, void *punk);
#pragma comment(linker, "/alternatename:?ji_0062af20@@YGJPAXKPBXPAPAX0@Z=?ji_0062af20@@YAXXZ")

class Rva00098A6F
{
public:
	void releaseDevices();
};

struct DI8Obj;
struct DI8Table
{
	void *slot0;
	void *slot1;
	void *slot2;
	long (__stdcall *createDevice)(DI8Obj *self, const void *rguid, void **device, void *outer);
};

struct DI8Obj
{
	DI8Table *m_table;
};

struct DIDevObj;
struct DIDevTable
{
	void *slot0;
	void *slot1;
	void *slot2;
	void *slot3;
	void *slot4;
	void *slot5;
	long (__stdcall *setProperty)(DIDevObj *self, const void *rguid, const void *prop);
	long (__stdcall *acquire)(DIDevObj *self);
	void *slot8;
	void *slot9;
	void *slot10;
	long (__stdcall *setDataFormat)(DIDevObj *self, const void *format);
	void *slot12;
	long (__stdcall *setCooperativeLevel)(DIDevObj *self, void *hwnd, unsigned long flags);
};

struct DIDevObj
{
	DIDevTable *m_table;
};

struct DIPROPHEADER
{
	unsigned long dwSize;
	unsigned long dwHeaderSize;
	unsigned long dwObj;
	unsigned long dwHow;
};

struct DIPROPDWORD
{
	DIPROPHEADER diph;
	unsigned long dwData;
};

class DirectInputKeyboard
{
public:
	void rva00098BD4();

private:
	unsigned char m_pad[0xE20];
	DI8Obj *m_pDirectInput;
	DIDevObj *m_pKeyboardDevice;
};

void DirectInputKeyboard::rva00098BD4()
{
	long hr;
	hr = ji_0062af20(ApplicationHInstance, 0x800, g_00CDF7E8, (void **)&m_pDirectInput, 0);
	if (hr < 0)
	{
		((Rva00098A6F *)this)->releaseDevices();
		return;
	}
	hr = m_pDirectInput->m_table->createDevice(m_pDirectInput, g_00CDF678, (void **)&m_pKeyboardDevice, 0);
	if (hr < 0)
	{
		((Rva00098A6F *)this)->releaseDevices();
		return;
	}
	hr = m_pKeyboardDevice->m_table->setDataFormat(m_pKeyboardDevice, g_00C7C9A4);
	if (hr < 0)
	{
		((Rva00098A6F *)this)->releaseDevices();
		return;
	}
	hr = m_pKeyboardDevice->m_table->setCooperativeLevel(m_pKeyboardDevice, Rva00DDE024, 6);
	if (hr < 0)
	{
		((Rva00098A6F *)this)->releaseDevices();
		return;
	}
	DIPROPDWORD prop;
	prop.diph.dwSize = 20;
	prop.diph.dwHeaderSize = 16;
	prop.diph.dwObj = 0;
	prop.diph.dwHow = 0;
	prop.dwData = 256;
	hr = m_pKeyboardDevice->m_table->setProperty(m_pKeyboardDevice, (const void *)1, &prop.diph);
	if (hr < 0)
	{
		((Rva00098A6F *)this)->releaseDevices();
		return;
	}
	m_pKeyboardDevice->m_table->acquire(m_pKeyboardDevice);
}
