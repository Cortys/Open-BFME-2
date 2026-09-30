// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
//
// ?rva0045F4D7@SpawnBehavior@@QAEPAVObject@@XZ, retail 0x0045F4D7, 170 bytes.
// SpawnBehavior helper returning Object*: iterates the ModuleData
// vector<AsciiString> at +0x20/+0x24, skipping duplicate names via a local
// AsciiString seeded from the empty string, resolving each distinct name
// through g_009FF000 and scanning the controlling Player via iterateObjects
// with a helper holding template/requester/result/best-float. Identity from
// caller 0x0045F9D8 (SpawnBehavior, uses return for setProducer) and the
// SpawnBehaviorCtor layout (this+4 ModuleData, this+8 Object).

class Object;
class Player;
class AsciiString;

template <typename T> class StringBase
{
public:
	int compare(const StringBase<T> &other) const;

private:
	friend class AsciiString;
	StringBase(const T *str);
	void releaseBuffer();

	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const char *str) : StringBase<char>(str) {}
	~AsciiString() { releaseBuffer(); }
	AsciiString &operator=(const AsciiString &other);
};

class Object
{
public:
	Player *getControllingPlayer() const;
};

class Player
{
public:
	void iterateObjects(void (*func)(Object *, void *), void *userData) const;
};

class Rva002D06CA
{
public:
	void *rva002D06CA(const AsciiString *key);
};

extern Rva002D06CA *g_009FF000;
extern float g_00C4254C;

class ModuleData
{
public:
	char pad[0x20];
	AsciiString *m_begin;
	AsciiString *m_end;
};

struct Helper0045F4D7
{
	void *m_template;
	Object *m_requester;
	Object *m_result;
	float m_best;
};

static void callback0045F4D7(Object *obj, void *userData)
{
	(void)obj;
	(void)userData;
}

class SpawnBehavior
{
public:
	virtual void anchor();
	Object *rva0045F4D7();

private:
	const ModuleData *m_moduleData;
	Object *m_object;
};

Object *SpawnBehavior::rva0045F4D7()
{
	Player *player = m_object->getControllingPlayer();
	const ModuleData *md = m_moduleData;
	Helper0045F4D7 helper;
	helper.m_template = 0;
	helper.m_result = 0;
	helper.m_requester = m_object;
	helper.m_best = g_00C4254C;
	AsciiString last("");
	for (AsciiString *it = md->m_begin; it != md->m_end; ++it)
	{
		if (last.compare(*it) == 0)
			continue;
		helper.m_template = g_009FF000->rva002D06CA(it);
		player->iterateObjects(callback0045F4D7, &helper);
		last = *it;
	}
	return helper.m_result;
}
