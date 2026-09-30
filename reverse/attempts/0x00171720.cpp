// ?rva00171720@MeshModelClass@@QAE_NXZ
// partial score=0.96 date=2026-09-30
// ?rva00171720@MeshModelClass@@QAE_NXZ
// partial score=0.96 date=2026-09-30
// cl: /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ?rva00171720@MeshModelClass@@QAE_NXZ retail 0x00171720 55B unlock lane.
// MeshModelClass predicate using CurMatDesc fields +0xB8/+0x108 and +0xBC,
// else PolygonRendererList emptiness via +0xA0/+0xA4. Evidence: CurMatDesc
// at +0x94 from sibling meshmdl.cpp Needs_Vertex_Normals; callers 0x14BD10.

class MeshMatDescClass
{
public:
	bool Do_Mappers_Need_Normals();
	friend class MeshModelClass;

private:
	unsigned char m_padB8[0xB8];
	int m_b8;
	unsigned char m_padBC[0x108 - 0xBC];
	int m_108;
};

class MeshModelClass
{
public:
	bool rva00171720();

private:
	unsigned char m_pad0[0x19];
	unsigned char m_flagByte;
	unsigned char m_pad1[0x94 - 0x1A];
	MeshMatDescClass *CurMatDesc;
	unsigned char m_pad98[0xA0 - 0x98];
	void *m_listHead;
	void *m_listFirst;
	unsigned char m_padA8[0xBC - 0xA8];
	int m_bc;
};

// ?rva00171720@MeshModelClass@@QAE_NXZ present-unmatched
bool MeshModelClass::rva00171720()
{
	if (CurMatDesc->m_b8 != 0)
		return m_bc != 0;
	if (CurMatDesc->m_108 != 0)
		return m_bc != 0;
	return m_listFirst != (void *)&m_listHead;
}
