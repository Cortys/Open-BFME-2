// ?get@Rva002E3A8DHolder@@QAEXPAURva002E3A8DPair@@H@Z
// partial score=0.92 date=2026-09-27
// ?get@Rva002E3A8DHolder@@QAEXPAURva002E3A8DPair@@H@Z
// partial score=0.92 date=2026-09-27
// cl: /O1 /MD
struct Rva002E3A8DPair
{
	float m_x;
	int m_y;
};
struct Rva002E3A8DHolder
{
	unsigned char m_pad[8];
	Rva002E3A8DPair *m_array;
	void get(Rva002E3A8DPair *out, int index);
};
void Rva002E3A8DHolder::get(Rva002E3A8DPair *out, int index)
{
	Rva002E3A8DPair *slot = &m_array[index];
	out->m_x = slot->m_x;
	out->m_y = slot->m_y;
}
