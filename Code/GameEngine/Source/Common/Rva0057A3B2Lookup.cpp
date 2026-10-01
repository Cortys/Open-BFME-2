// cl: /O1 /MD
// ?Rva0057A3B2Get@@YAHH@Z @0x0057A3B2 33B
// Linear search of 6-entry key/value table at 0x00C6EF40; returns value or -1.
// Evidence: callers at 0x0057AB2B 0x0057AB36 pass int and use signed result.
struct Rva0057A3B2Entry
{
	int m_key;
	int m_value;
};
extern Rva0057A3B2Entry g_00C6EF40[6];
int __cdecl Rva0057A3B2Get(int val)
{
	for (unsigned int i = 0; i < 6; ++i)
	{
		if (val == g_00C6EF40[i].m_key)
			return g_00C6EF40[i].m_value;
	}
	return -1;
}
