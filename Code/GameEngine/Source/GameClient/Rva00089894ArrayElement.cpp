// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG
// RVA 0x00089894: constructor callback passed by the BFME1-guided owner
// at 0x0008990C to the real MSVC vector constructor iterator (255 and 4
// elements, stride 20). The RET ends at the rowed 0x000898B0 assignment.
// Target writes three zero floats and zero words at +0xC/+0x10. Cleanup
// callback 0x0004F82B releases string-compatible storage at +0xC; its 8 bytes do
// not identify this 20-byte element as the existing 16-byte GeometryRecord.
// This non-owning storage view models the constructor alone. Original names,
// owning C++ type and the meaning of the final word are unknown.

class Rva00089894ArrayElement
{
public:
	Rva00089894ArrayElement();
private:
	float m_00, m_04, m_08;
	void *m_0C;
	int m_10;
};

Rva00089894ArrayElement::Rva00089894ArrayElement() : m_0C(0), m_10(0)
{
	m_00 = 0.0f;
	m_04 = 0.0f;
	m_08 = 0.0f;
}
