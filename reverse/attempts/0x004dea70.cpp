// ?rva004DEA70@Rva004DEA70@@QAEPAXPAUArg1_004DEA70@@PBUCoord3DBase@@@Z
// partial score=0.94 date=2026-09-28
// ?rva004DEA70@Rva004DEA70@@QAEPAXPAUArg1_004DEA70@@PBUCoord3DBase@@@Z
// partial score=0.94 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva004DEA70@Rva004DEA70@@QAEPAXPAUArg1_004DEA70@@PBUCoord3DBase@@@Z retail 0x004DEA70 64B
// Evidence: unlock lane; callee equals 0x00003702; caller jmp 0x0028BE7F (Object+0x240 tail); prev ModuleNameGetters next FiringTrackerPoolKey; members +0x20 ptr +0x24 id +0x28 Coord3D +0x34 flag.
struct Coord3DBase
{
	float x;
	float y;
	float z;
};
class Coord3D : public Coord3DBase
{
public:
	bool equals(const Coord3DBase &that) const;
};
struct Arg1_004DEA70
{
	char m_pad[0x74];
	int m_74;
};
class Rva004DEA70
{
public:
	void *rva004DEA70(Arg1_004DEA70 *a1, const Coord3DBase *a2);
private:
	char m_pad00[0x20];
	void *m_ptr20;
	int m_24;
	Coord3D m_coord28;
	bool m_flag34;
};
// ?rva004DEA70@Rva004DEA70@@QAEPAXPAUArg1_004DEA70@@PBUCoord3DBase@@@Z present-unmatched
void *Rva004DEA70::rva004DEA70(Arg1_004DEA70 *a1, const Coord3DBase *a2)
{
	if (a1 == 0) {
		if (m_flag34 != 0 && a2 != 0 && m_coord28.equals(*a2))
			return m_ptr20;
		return 0;
	} else {
		if (m_flag34 == 0 && a1->m_74 == m_24)
			return m_ptr20;
		return 0;
	}
}
