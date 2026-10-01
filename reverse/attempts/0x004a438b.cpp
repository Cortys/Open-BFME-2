// ?rva004A438B@Rva004A438B@@QBEMXZ
// partial score=0.93 date=2026-10-01
// ?rva004A438B@Rva004A438B@@QBEMXZ
// partial score=0.93 date=2026-10-01
// cl: /DNDEBUG /MD /EHsc /arch:SSE
// ?rva004A438B@Rva004A438B@@QBEMXZ @0x004A438B 94B evidence: BFME1 donor StructureCollapseGetCollapseHeight.cpp GeometryInfo row 0x006BD7C0 callers 0x004A461A 0x004A4948
class GeometryInfo
{
public:
	float getMaxHeightAbovePosition() const;
};

struct CollapseTemplate
{
	char m_pad[0xA0];
	GeometryInfo m_geometryInfo;
};

struct CollapseThing
{
	void *m_vtable;
	CollapseTemplate *m_template;
};

struct CollapseObject
{
	char m_pad[0xF4];
	bool m_useGeometry;
	char m_pad2[3];
	float m_height;
};

class Rva004A438B
{
public:
	float rva004A438B() const;

private:
	void *m_vtable;
	CollapseObject *m_object;
	CollapseThing *m_thing;
};

// ?rva004A438B@Rva004A438B@@QBEMXZ present-unmatched
float Rva004A438B::rva004A438B() const
{
	CollapseObject *object = m_object;
	if (!object->m_useGeometry)
		return object->m_height;
	float height = object->m_height;
	float geometryHeight = m_thing->m_template->m_geometryInfo.getMaxHeightAbovePosition();
	if (geometryHeight < height)
		return height;
	return m_thing->m_template->m_geometryInfo.getMaxHeightAbovePosition();
}
