// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Open-BFME-1 donor at cd32c8ef06dfb0d995b2f47e93e41622e4447092:
// Rva007F1DE0DerivedCtors.cpp. The mapped BFME2 targets below each install
// vptrs at +0/+4 and copy the constructor argument to +8; class names and
// shared payload interpretation remain donor-derived.

class Rva007F1DE0BaseA
{
public:
	virtual void primary();
};

class Rva007F1DE0BaseB
{
public:
	virtual void secondary();
	void *m_payload;
	Rva007F1DE0BaseB(void *payload) : m_payload(payload) {}
};

#define BFME_DERIVED_CTOR(RVA) \
class Rva##RVA##Object : public Rva007F1DE0BaseA, public Rva007F1DE0BaseB \
{ \
public: \
	Rva##RVA##Object(void *payload); \
	virtual void primary(); \
	virtual void secondary(); \
}; \
Rva##RVA##Object::Rva##RVA##Object(void *payload) : Rva007F1DE0BaseB(payload) {}

BFME_DERIVED_CTOR(007F1DE0)
BFME_DERIVED_CTOR(007F2680)
BFME_DERIVED_CTOR(007F2F80)
BFME_DERIVED_CTOR(007FAE20)
BFME_DERIVED_CTOR(007FC150)
