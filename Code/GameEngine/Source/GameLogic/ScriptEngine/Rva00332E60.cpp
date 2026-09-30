// cl: /DNDEBUG /MD /O1
// ?rva00332E60@Rva00332E60@@QAEPAXH@Z @0x00332E60 35B
// retail 0x00332E60 35 bytes unlock search 17-entry table at +0x14 each 8 bytes
// compares first dword to arg returns entry pointer or null caller 0x00333918
// neighbours prev 0x00332C7A ScriptEventFlags and next 0x00332E9D Object156Copy

struct Rva00332E60Entry
{
	unsigned int key;
	unsigned int value;
};

class Rva00332E60
{
public:
	void *rva00332E60(int key);

private:
	unsigned char m_pad[20];
	Rva00332E60Entry m_entries[17];
};

void *Rva00332E60::rva00332E60(int key)
{
	for (int i = 0; i < 17; ++i)
	{
		if (m_entries[i].key == (unsigned int)key)
			return &m_entries[i];
	}
	return 0;
}
