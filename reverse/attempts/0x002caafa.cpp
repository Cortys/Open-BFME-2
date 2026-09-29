// ?rva002CAAFA@Rva002CAAFA@@QAE_NPAVObject@@PAUCoord3D@@@Z
// partial score=0.95 date=2026-09-29
// ?rva002CAAFA@Rva002CAAFA@@QAE_NPAVObject@@PAUCoord3D@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
//
// ?rva002CAAFA@Rva002CAAFA@@QAE_NPAVObject@@PAUCoord3D@@@Z @0x002CAAFA 64B: bone-name gate around Object::getSingleLogicalBonePosition.
// AsciiString at +0x90; when empty return false, else forward its str() (m_data+8 with "" fallback) plus the caller's Object and Coord3D to the rowed
// ?getSingleLogicalBonePosition@Object@@QBE_NPBDPAUCoord3D@@PAVMatrix3D@@@Z at 0x0028BEE0 with a null transform. Callers 0x002CAB73 0x0036C0BD 0x0036C4A7.
template <typename T>
class StringBase
{
public:
	bool isEmpty() const;
	const char *str() const { return m_data ? m_data + 8 : ""; }

private:
	char *m_data;
};

class AsciiString : public StringBase<char>
{
};

struct Coord3D
{
	float x, y, z;
};

class Matrix3D;
class Object
{
public:
	bool getSingleLogicalBonePosition(const char *boneName, Coord3D *position, Matrix3D *transform) const;
};

class Rva002CAAFA
{
public:
	bool rva002CAAFA(Object *obj, Coord3D *out);

private:
	char m_pad[0x90];
	AsciiString m_bone90;
};

// ?rva002CAAFA@Rva002CAAFA@@QAE_NPAVObject@@PAUCoord3D@@@Z present-unmatched
bool Rva002CAAFA::rva002CAAFA(Object *obj, Coord3D *out)
{
	if (m_bone90.isEmpty())
		return false;
	if (obj->getSingleLogicalBonePosition(m_bone90.str(), out, 0))
		return true;
	return false;
}
