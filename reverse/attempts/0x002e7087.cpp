// ?rva002E7087@Rva002E7087@@QAEXHHHHHHDDHHPAHD@Z
// partial score=0.88 date=2026-09-29
// ?rva002E7087@Rva002E7087@@QAEXHHHHHHDDHHPAHD@Z
// partial score=0.88 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva002E7087@Rva002E7087@@QAEXHHHHHHDDHHPAHD@Z (placeholder), retail 0x002E7087, 97 bytes.
// __thiscall struct initializer copying 12 stack args to +0x0..+0x38 with a
// 3-dword chase through the pointer arg at +0x30. Class and **/
class Rva002E7087
{
public:
	void rva002E7087(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9, int a10, int *a11, char a12);
private:
	int m_00;
	int m_04;
	int m_08;
	char m_0C;
	char m_pad0D[3];
	int m_10;
	int m_14;
	int m_18;
	int m_1C;
	char m_20;
	char m_pad21[3];
	int m_24;
	int m_28;
	int m_2C;
	int m_30;
	int m_34;
	char m_38;
	char m_pad39[3];
};

// ?rva002E7087@Rva002E7087@@QAEXHHHHHHDDHHPAHD@Z present-unmatched
void Rva002E7087::rva002E7087(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9, int a10, int *a11, char a12)
{
	Rva002E7087 *self = this;
	self->m_00 = a1;
	self->m_04 = a2;
	self->m_08 = a9;
	self->m_0C = a7;
	self->m_10 = a10;
	self->m_14 = a11[0];
	self->m_18 = a11[1];
	self->m_1C = a11[2];
	self->m_20 = a8;
	self->m_24 = a5;
	self->m_28 = a3;
	self->m_2C = a4;
	self->m_34 = (int)a11;
	self->m_30 = a6;
	self->m_38 = a12;
}
