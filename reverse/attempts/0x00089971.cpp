// ??1Rva0089971@@UAE@XZ
// partial score=0.6818181818 date=2026-10-03
// cl: /O1 /G7 /MD /EHsc /DNDEBUG /Ireference/shims/bfme2_ascii
// ??0Rva000851F3@@QAE@XZ, retail 0x000851F3, 71 bytes.
// Ctor storing the real three-slot vtable BC745C at +0, then ParabolicEase
// at +0x10 via rowed 0x0008517E
// with (0 0 1) then zeroing +4 +8 +0x20 +0x24 +0x28 +0x18 +0x1c.
// Evidence: rowed ParabolicEase forward 0x0008517E; callers 0x0008990C 0x00312C95.
// BC745C = {scalar-delete 85241, purecall 3B810, purecall 3B810}; its
// first pointer incidentally spells "ARH". Plain cleanup 8523A restores
// the table; scalar-delete 85241 is 29B/RET4 and restores it before delete.
// Derived BC74F4 has matching RET4/RET24 slots. The first slot argument
// and final unused word of the second retain only their ABI word views.
// Original names, complete layout and historical class identity are unknown.
typedef float Real;

class ParabolicEase
{
public:
	void rva0030E51F(Real easeInTime, Real easeOutTime, Real duration);
	ParabolicEase *rva0008517E(Real easeInTime, Real easeOutTime, Real duration);
	Real operator()(Real param) const;
private:
	Real m_in;
	Real m_out;
};

class Rva000851F3
{
public:
	Rva000851F3();
	// ?Rva000851F3::~Rva000851F3 present-unmatched
	virtual ~Rva000851F3() {}
	virtual void slot1(int) = 0;
	virtual void slot2(int, int, Real, Real, int, int) = 0;
protected:
	int m_04;
	int m_08;
	int m_0C;
	ParabolicEase m_10;
	float m_18;
	float m_1C;
	int m_20;
	bool m_24;
	int m_28;
};


#include "ascii_string.h"
class Rva00089894ArrayElement
{
public:
 Rva00089894ArrayElement();
 ~Rva00089894ArrayElement();
private:
 float m_00, m_04, m_08;
 AsciiString m_0C;
 int m_10;
};

class __declspec(novtable) Rva0089971 : public Rva000851F3
{
public:
 Rva0089971();
 virtual ~Rva0089971();
 // ?Rva0089971::slot1 present-unmatched
 virtual void slot1(int) {}
 virtual void slot2(int, int, Real, Real, int, int);
private:
 Rva00089894ArrayElement m_arr255[255];
 Rva00089894ArrayElement m_arr4[4];
 char m_padding1468[0x1864-0x1468];
 int m_values[257];
 char m_padding1C68[12];
 int m_filled[255];
 int m_numValues;
};
Rva0089971::~Rva0089971() {}
