// cl: /O1
// ?rva0030B2B6@Rva0030B2B6@@QAEXPAVDataChunkOutput@@@Z retail 0x0030B2B6 72B: writes Elem array count then each pair via writeInt/writeReal.
// Evidence: sub sar 3 count plus fld fstp loop with add 8; callees rowed writeInt/writeReal ICF-folded at 0x00306CFF.

class DataChunkOutput
{
public:
	void writeInt(int value);
	void writeReal(float value);
};

struct Rva0030B2B6Elem
{
	float a;
	float b;
};

class Rva0030B2B6
{
public:
	void rva0030B2B6(DataChunkOutput *out);
private:
	Rva0030B2B6Elem *m_begin;
	Rva0030B2B6Elem *m_end;
};

void Rva0030B2B6::rva0030B2B6(DataChunkOutput *out)
{
	out->writeInt(m_end - m_begin);
	Rva0030B2B6Elem *end = m_end;
	Rva0030B2B6Elem *elem = m_begin;
	while (elem != end)
	{
		out->writeReal(elem->a);
		out->writeReal(elem->b);
		++elem;
	}
}
