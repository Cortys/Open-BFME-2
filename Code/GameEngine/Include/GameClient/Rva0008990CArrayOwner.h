#pragma once
// Target BC745C/BC74F4 and their RET4/RET24 slots establish this dispatch
// order. Owner8990C/89971 establishes two 20B owning-element arrays (255/4)
// starting at2C/1418. Cleanup4F82B reaches StringBase<char>::releaseBuffer
// at36410 from element+C. The initializer accesses through2070. These are
// observed prefixes; original names and complete sizes remain unknown.
// The destructor TU uses novtable solely to reproduce retail's absent entry
// vptr store. This does not claim a historical source annotation.
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
	virtual void rva00047A69C(int) = 0;
	virtual void rva00086B2C(int, int, Real, Real, int, int) = 0;
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


#include "../../../../reference/shims/bfme2_ascii/ascii_string.h"
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

#ifndef BFME_ARRAY_OWNER_ATTRIBUTES
#define BFME_ARRAY_OWNER_ATTRIBUTES
#endif
class BFME_ARRAY_OWNER_ATTRIBUTES Rva0089971 : public Rva000851F3
{
public:
 Rva0089971();
 virtual ~Rva0089971();
 // ?Rva0089971::rva00047A69C present-unmatched
 virtual void rva00047A69C(int) {}
 virtual void rva00086B2C(int, int, Real, Real, int, int);
private:
 Rva00089894ArrayElement m_arr255[255];
 Rva00089894ArrayElement m_arr4[4];
 char m_padding1468[0x1864-0x1468];
 int m_values[257];
 char m_padding1C68[12];
 int m_filled[255];
 int m_numValues;
};

#undef BFME_ARRAY_OWNER_ATTRIBUTES
