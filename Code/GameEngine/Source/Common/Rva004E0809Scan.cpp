// cl: /O1
// ?rva004E0809@Rva004E0809@@QAEXXZ @0x004E0809 60B
// Scan pointer range [+0x30,+0x34) and keep last non-null virtual results:
// slot 0x20 -> [+0x40], slot 0x28 -> [+0x44]. Retail is and [esi+0x40],0 /
// and [esi+0x44],0 / mov ebx,[esi+0x34] / mov edi,[esi+0x30] / loop with two
// vtable calls plus test/je/store and add edi,4 / cmp edi,ebx / jne (60B).
// Evidence: unlock lane; callees are indirect virtuals so gate-ready; callers
// at 0x004E0E78 0x004E119C; neighbours Rva004E0790Release/Rva004E08F6Set share /O1.
class Rva004E0809Elem
{
public:
	virtual void vf0();
	virtual void vf1();
	virtual void vf2();
	virtual void vf3();
	virtual void vf4();
	virtual void vf5();
	virtual void vf6();
	virtual void vf7();
	virtual void *vf8();
	virtual void vf9();
	virtual void *vf10();
};
class Rva004E0809
{
public:
	void rva004E0809();
	char m_pad[0x30];
	Rva004E0809Elem **m_begin;
	Rva004E0809Elem **m_end;
	char m_pad2[8];
	void *m_40;
	void *m_44;
};
void Rva004E0809::rva004E0809()
{
	m_40 = 0;
	m_44 = 0;
	Rva004E0809Elem **end = m_end;
	for (Rva004E0809Elem **p = m_begin; p != end; ++p) {
		void *a = (*p)->vf8();
		if (a)
			m_40 = a;
		void *b = (*p)->vf10();
		if (b)
			m_44 = b;
	}
}
