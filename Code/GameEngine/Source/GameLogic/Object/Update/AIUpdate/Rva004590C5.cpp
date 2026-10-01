// cl: /O1 /DNDEBUG /MD
//
// ?rva004590C5@Rva004590C5@@QAEXXZ, retail 0x004590C5 33B. Chain via 0x0045906E.
// m_20 = m_04->v8 plus rva0045906E(true) on same this plus
// UpdateModule::setWakeFrame(m_08, UPDATE_SLEEP_NONE). Prev 0x45906E.
class Object;

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1
};

class UpdateModule
{
	friend class Rva004590C5;
protected:
	void setWakeFrame(Object *obj, UpdateSleepTime delay);
};

class Rva0045906E
{
public:
	void rva0045906E(bool b);
};

struct Rva004590C5Helper
{
	unsigned char m_pad[8];
	int m_v8;
};

class Rva004590C5
{
public:
	void rva004590C5();
private:
	unsigned char m_pad00[4];
	Rva004590C5Helper *m_04;
	Object *m_08;
	unsigned char m_pad0C[0x20 - 0x0C];
	int m_20;
};

void Rva004590C5::rva004590C5()
{
	m_20 = m_04->m_v8;
	((Rva0045906E *)this)->rva0045906E(true);
	((UpdateModule *)this)->setWakeFrame(m_08, UPDATE_SLEEP_NONE);
}
