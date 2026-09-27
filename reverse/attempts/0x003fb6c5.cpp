// ?Rva003FB6C5@Rva005C4B1B@@UAEXABVVector3@@@Z
// partial score=0.95 date=2026-09-26
// ?Rva003FB6C5@Rva005C4B1B@@UAEXABVVector3@@@Z
// partial score=0.95 date=2026-09-26
// cl: /O1 /MD /arch:SSE
//
// ?Rva003FB6C5@Rva005C4B1B@@UAEXABVVector3@@@Z, retail 0x003FB6C5, 206 bytes.
// Virtual slot 7 (offset 0x1C) of vtable 0x008747B8 (class of rowed
// ??1Rva005C4B1B at 0x005C4B1B with ??_G at 0x005C4D2F). Validates RenderObj
// at +8 via slot 20 (0x50 Validate_Transform), builds Matrix3D temp (48B)
// from its Transform at +0x18 (11 floats, Tx/Ty redundant) plus Vector3 arg
// translation (Tx/Ty/Tz at +0/+4/+8), calls slot 21 (0x54 Set_Transform) on
// +8 and conditionally +0x14. Callers 0x003FD9B1/0x003FDA27 pass through
// Vector3 pointer. Honest address name: slot index is the proof.
class Vector3 { public: float X, Y, Z; };
class Matrix3D { public: float m[12]; };
class RenderObjDummy {
public:
    virtual ~RenderObjDummy();
    virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04();
    virtual void s05(); virtual void s06(); virtual void s07(); virtual void s08();
    virtual void s09(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19();
    virtual void Validate_Transform() const;
    virtual void Set_Transform(const Matrix3D &m);
    char m_pad[20];
    Matrix3D m_trans;
};
class Rva005C4B1B {
public:
    virtual ~Rva005C4B1B();
    virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6();
    virtual void Rva003FB6C5(const Vector3 &pos);
private:
    int m_4;
    RenderObjDummy *m_8;
    int m_C;
    int m_10;
    RenderObjDummy *m_14;
};
// ?Rva003FB6C5@Rva005C4B1B@@UAEXABVVector3@@@Z present-unmatched
void Rva005C4B1B::Rva003FB6C5(const Vector3 &pos)
{
    RenderObjDummy *a = m_8;
    if (!a)
        return;
    a->Validate_Transform();
    float py = pos.Y;
    float pz = pos.Z;
    Matrix3D tm;
    tm.m[0] = a->m_trans.m[0];
    tm.m[1] = a->m_trans.m[1];
    tm.m[2] = a->m_trans.m[2];
    tm.m[3] = a->m_trans.m[3];
    tm.m[4] = a->m_trans.m[4];
    tm.m[5] = a->m_trans.m[5];
    tm.m[6] = a->m_trans.m[6];
    tm.m[7] = a->m_trans.m[7];
    tm.m[8] = a->m_trans.m[8];
    tm.m[9] = a->m_trans.m[9];
    tm.m[10] = a->m_trans.m[10];
    tm.m[11] = a->m_trans.m[11];
    tm.m[3] = pos.X;
    tm.m[7] = py;
    tm.m[11] = pz;
    m_8->Set_Transform(tm);
    if (m_14)
        m_14->Set_Transform(tm);
}
