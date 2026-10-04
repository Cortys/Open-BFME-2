// ?rva004AE6D7@ToggleDeploySpecialAbilityUpdate@@QAEXPAX@Z
// partial score=0.98 date=2026-10-04
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva004AE5B8@ToggleDeploySpecialAbilityUpdate@@QAEXPAX@Z retail 0x004AE5B8 124B
// Evidence: vslot 23 of vtable 0x00855370 for ToggleDeploySpecialAbilityUpdate; audio event via rowed BfmeAudioEventPrefix136 plus CondSetter plus TheAudio slot 0x64 plus DeployStyle helper; caller none
struct OpaqueRefElement4;
class BfmeStringTailRecord144
{
public:
	virtual ~BfmeStringTailRecord144();
};
class BfmeAudioEventPrefix136 : public BfmeStringTailRecord144
{
public:
	BfmeAudioEventPrefix136(const OpaqueRefElement4 &o, int v);
private:
	char m_pad[136 - sizeof(BfmeStringTailRecord144)];
};
class Rva002D9531
{
public:
	void rva002D9531(int v);
};
class AudioManager
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
	virtual void v09();
	virtual void v10();
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
	virtual void v24();
	virtual int v25(BfmeAudioEventPrefix136 *p);
};
extern AudioManager *TheAudio;
class DeployStyleAIUpdate
{
public:
	void rva0048E6D2();
	void rva0048E6AB();
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
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
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
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
	virtual void v42();
	virtual void v43();
	virtual void v44();
	virtual void v45();
	virtual void v46();
	virtual void v47();
	virtual void v48();
	virtual void v49();
	virtual void v50();
	virtual void v51();
	virtual void v52();
	virtual void v53();
	virtual void v54();
	virtual void v55();
	virtual void v56();
	virtual void v57();
	virtual void v58();
	virtual void v59();
	virtual void v60();
	virtual void v61();
	virtual void v62();
	virtual void v63();
	virtual void v64();
	virtual void v65();
	virtual void v66();
	virtual void v67();
	virtual void v68();
	virtual void v69();
	virtual void v70();
	virtual void v71();
	virtual void v72();
	virtual void v73();
	virtual void v74();
	virtual void v75();
	virtual void v76();
	virtual void v77();
	virtual void v78();
	virtual void v79();
	virtual void v80();
	virtual void v81();
	virtual void v82();
	virtual void v83();
	virtual void v84();
	virtual void v85();
	virtual void v86();
	virtual void v87();
	virtual void v88();
	virtual void v89();
	virtual void v90();
	virtual void v91();
	virtual void v92();
	virtual void v93();
	virtual void v94();
	virtual void v95();
	virtual void v96();
	virtual void v97();
	virtual void v98();
	virtual void v99();
	virtual void v100();
	virtual void v101();
	virtual void v102();
	virtual void v103();
	virtual void v104();
	virtual void v105();
	virtual void v106();
	virtual void v107();
	virtual void v108();
	virtual void v109();
	virtual void v110();
	virtual bool v111();
};
struct OpaqueRefElement4 {
	int m_dummy;
};
struct Thing {
	char m_pad[0xCC];
	OpaqueRefElement4 m_opaque;
};
struct Rva004AE5B8Data08 {
	char m_pad[0x74];
	int m_74;
};
class Rva0044EF5E
{
public:
	Rva0044EF5E();
protected:
	const void *m_vtable;
	Thing *m_owner;
	Rva004AE5B8Data08 *m_p08;
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_pad[0x20 - 0x14];
};
class Rva004AE6D7P20
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
	virtual bool v08(int v);
};
class Object
{
public:
	bool rva0028B7C8() const;
};
enum CommandSourceType {
	kCommandSourceInvalid = 0,
	kCommandSourcePlayer = 1,
	kCommandSourceAI = 2
};
class AICommandInterface
{
public:
	void aiIdle(CommandSourceType t);
};
class ToggleDeploySpecialAbilityUpdate : public Rva0044EF5E
{
public:
	void rva004AE5B8(void *arg);
	void rva004AE6D7(void *arg);
private:
	Rva004AE6D7P20 m_p20;
};
struct Rva004AE5B8Arg {
	char m_pad[0x258];
	DeployStyleAIUpdate *m_258;
};
void ToggleDeploySpecialAbilityUpdate::rva004AE5B8(void *argVoid)
{
	Rva004AE5B8Arg *arg = (Rva004AE5B8Arg *)argVoid;
	BfmeAudioEventPrefix136 tmp(*(OpaqueRefElement4 *)((char *)m_owner + 0xCC), 0);
	Rva004AE5B8Data08 *p08 = m_p08;
	((Rva002D9531 *)&tmp)->rva002D9531(p08->m_74);
	TheAudio->v25(&tmp);
	arg->m_258->rva0048E6D2();
}
// ?rva004AE6D7@ToggleDeploySpecialAbilityUpdate@@QAEXPAX@Z retail 0x004AE6D7 183B
// Evidence: vslot 24 of same vtable via first gate plus Object gate plus DeployStyle virtual plus aiIdle plus same audio tail with plus 0xC8 plus final helper
// ?rva004AE6D7@ToggleDeploySpecialAbilityUpdate@@QAEXPAX@Z present-unmatched
void ToggleDeploySpecialAbilityUpdate::rva004AE6D7(void *argVoid)
{
	if (!m_p20.v08(0))
		return;
	Rva004AE5B8Arg *arg = (Rva004AE5B8Arg *)argVoid;
	DeployStyleAIUpdate *ds = arg->m_258;
	if (!ds)
		return;
	if (((Object *)arg)->rva0028B7C8() || ds->v111()) {
		((AICommandInterface *)((char *)ds + 0x20))->aiIdle(kCommandSourceAI);
	}
	BfmeAudioEventPrefix136 tmp(*(OpaqueRefElement4 *)((char *)m_owner + 0xC8), 0);
	Rva004AE5B8Data08 *p08 = m_p08;
	((Rva002D9531 *)&tmp)->rva002D9531(p08->m_74);
	TheAudio->v25(&tmp);
	ds->rva0048E6AB();
}
