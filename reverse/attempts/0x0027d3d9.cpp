// ?Rva0027D3D9Forward@@YGXHHPAVMatrix3D@@M@Z
// partial score=0.93 date=2026-09-29
// ?Rva0027D3D9Forward@@YGXHHPAVMatrix3D@@M@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD
// ?Rva0027D3D9Forward@@YGXHHPAVMatrix3D@@M@Z, retail 0x0027D3D9, 50 bytes.
// Free __stdcall forwarder via global 0x009FF080 to slot20 (0x50)
// (a1, a2, z-rotation of m, f). Callers 0x1F18F1/0x1F1FF4/0x243A9B/0x245518/
// 0x4C3A92. Same manager family as Rva0027D1A4Forward/Rva0027D3CBForward.
// Get_Z_Rotation is rowed in matrix3d.cpp. No donor: honest address name.
class Matrix3D
{
public:
	float Get_Z_Rotation() const;
};

class Rva009FF080Manager0027D3D9
{
public:
	virtual void _slot00();
	virtual void _slot01();
	virtual void _slot02();
	virtual void _slot03();
	virtual void _slot04();
	virtual void _slot05();
	virtual void _slot06();
	virtual void _slot07();
	virtual void _slot08();
	virtual void _slot09();
	virtual void _slot10();
	virtual void _slot11();
	virtual void _slot12();
	virtual void _slot13();
	virtual void _slot14();
	virtual void _slot15();
	virtual void _slot16();
	virtual void _slot17();
	virtual void _slot18();
	virtual void _slot19();
	virtual void _slot20(int a, int b, float c, float d);
};

#define TheRva009FF080Manager0027D3D9 (*(Rva009FF080Manager0027D3D9 **)0x00DFF080)

// ?Rva0027D3D9Forward@@YGXHHPAVMatrix3D@@M@Z present-unmatched
void __stdcall Rva0027D3D9Forward(int a, int b, Matrix3D *m, float f)
{
	Rva009FF080Manager0027D3D9 *manager = TheRva009FF080Manager0027D3D9;
	float w = f;
	float z = m->Get_Z_Rotation();
	manager->_slot20(a, b, z, w);
}
