// ?Rva004073DCFind@@YGPAVAsciiString@@PAV1@PBVRva002B224BDwordField@@@Z
// partial score=0.8 date=2026-09-30
// ?Rva004073DCFind@@YGPAVAsciiString@@PAV1@PBVRva002B224BDwordField@@@Z
// partial score=0.80 date=2026-09-30
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

// ?Rva004073DCFind@@YGPAVAsciiString@@PAV1@PBVRva002B224BDwordField@@@Z retail 0x004073DC 177B
// evidence: sole caller 0x004086D4; callees rowed get 0x2B224B releaseBuffer 0x36410 pins op= 0x366F0 copy 0x365F0
// Scans a pointer array from Rva002B224BDwordField::get for the first entry whose
// vA8/v24/v28 chain yields a non-empty AsciiString; placement-copies it to out.
#include <new>

template <typename T> class StringBase
{
public:
	StringBase() {}
	StringBase(const StringBase &o);
	void *m_data;
protected:
	void releaseBuffer();
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() { m_data = 0; }
	AsciiString(const AsciiString &o) : StringBase<char>(o) {}
	AsciiString &operator=(const AsciiString &o);
	~AsciiString() { releaseBuffer(); }
};

class Rva002B224BDwordField
{
public:
	int get() const;
};

class Rva004073DCElem
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual int v24();
	virtual AsciiString *v28(AsciiString *out, int unused);
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24b();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28b();
	virtual void v29();
	virtual void v30();
	virtual void v31();
	virtual void v32();
	virtual void v33();
	virtual void v34();
	virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38();
	virtual void v39();
	virtual void v40();
	virtual void v41();
	virtual void *vA8();
};

// ?Rva004073DCFind@@YGPAVAsciiString@@PAV1@PBVRva002B224BDwordField@@@Z present-unmatched
AsciiString *__stdcall Rva004073DCFind(AsciiString *out, const Rva002B224BDwordField *field)
{
	volatile int done = 0;
	AsciiString result;
	unsigned char tmpStorage[4];
	int cursor = field->get();

	for (;;)
	{
		if (result.m_data && *(unsigned short *)((char *)result.m_data + 4))
			break;
		Rva004073DCElem *e = *(Rva004073DCElem **)cursor;
		if (!e)
			break;
		Rva004073DCElem *v = (Rva004073DCElem *)e->vA8();
		if (v && v->v24())
		{
			AsciiString *s = v->v28((AsciiString *)tmpStorage, 0);
			result = *s;
			((AsciiString *)tmpStorage)->~AsciiString();
		}
		cursor += 4;
	}

	new (out) AsciiString(result);
	done = 1;
	return out;
}
