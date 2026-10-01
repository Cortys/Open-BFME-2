// ?rva002AF0C5@Player@@QAEX_N@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /GX /arch:SSE
//
// ?rva002AF0C5@Player@@QAEX_N@Z, retail 0x002AF0C5, 214 bytes.
// Player method taking bool (callers at 0x003BBBB6 and 0x003BBBE0 pass Player* in ecx plus push 1).
// Outer list at Player+0x32c, per-node payload at +8 holding Team* at +0x334,
// Team member iteration via rowed iterate_TeamMemberList plus rowed advance,
// AICommandInterface subobject at AI+0x20 via rowed rva0026C26D, plus virtual
// checks at +0x1b8/+0x17c/+0x2c and DwordField getter row at 0x005C4AF5.
// Evidence: Player callers, lea ecx [esi+0x20] AICommandInterface, Team iterate.

typedef int Int;
struct Coord3D { float x; float y; float z; };

class Object;
class Team;
class AICommandInterface;
class Rva005C4AF5DwordField;

class Rva005C4AF5DwordField
{
public:
	int get() const;
	char m_lead[0x40];
	int m_value;
};

class AICommandInterface
{
public:
	virtual void aiDoCommand(const void *parms) = 0;
	void rva0026C26D(const Coord3D *pos, Int cmdSource);
};

class AISecond
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual void s6();
	virtual void s7();
	virtual void s8();
	virtual void s9();
	virtual void s10();
	virtual void s11(Int v);
};

class AIClass
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
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
	virtual AISecond *v95();
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
	virtual bool v110();
};

class FlagObj
{
public:
	char m_pad[0x108];
	unsigned char m_flag;
};

class Object
{
public:
	void *m_vptr;
	FlagObj *m_04;
	char m_08[0x30];
	Coord3D m_38;
	char m_44[0x258 - 0x44];
	AIClass *m_258;
};

template<class OBJCLASS>
class DLINK_ITERATOR
{
public:
	Object *cur() const { return (Object *)m_cur; }
	bool done() const { return m_cur == 0; }
private:
	OBJCLASS *m_cur;
	char m_rest[28];
};

template<class OBJCLASS>
class Rva001705A0DlinkIterator
{
public:
	void advance();
private:
	OBJCLASS *m_cur;
	char m_rest[28];
};

class Team
{
public:
	DLINK_ITERATOR<Object> iterate_TeamMemberList() const;
	int get() const;
private:
	unsigned char m_pad00[0x08];
	unsigned int m_id;
	unsigned char m_pad0C[0x30 - 0x0C];
	void *m_proto;
	unsigned char m_pad34[0x38 - 0x34];
	Object *m_head;
	unsigned char m_pad3C[0x40 - 0x3C];
	int m_40;
};

struct OuterPayload
{
	char m_pad[0x334];
	Team *m_team;
};

struct OuterNode
{
	OuterNode *m_next;
	int m_04;
	OuterPayload *m_08;
};

class Player
{
public:
	void rva002AF0C5(bool flag);
private:
	char m_pad[0x32c];
	OuterNode *m_head;
};

// ?rva002AF0C5@Player@@QAEX_N@Z present-unmatched
void Player::rva002AF0C5(bool flag)
{
	Team *team;
	OuterNode *cur = m_head->m_next;
	if (cur == m_head)
		return;
	typedef int (__fastcall *GetFn)(Rva005C4AF5DwordField *);
	int (Rva005C4AF5DwordField::*mp)() const = &Rva005C4AF5DwordField::get;
	volatile GetFn pf = *(GetFn *)&mp;
	volatile int base = 0;
	do {
		OuterPayload *payload = cur->m_08;
		team = payload->m_team;
		while (team != 0) {
			DLINK_ITERATOR<Object> it = team->iterate_TeamMemberList();
			for (;;) {
				Object *obj = it.cur();
				if (obj == 0)
					break;
				FlagObj *fo = obj->m_04;
				if (fo->m_flag & 0x80) {
					((Rva001705A0DlinkIterator<Object> *)&it)->advance();
					continue;
				}
				AIClass *ai = obj->m_258;
				if (ai == 0) {
					((Rva001705A0DlinkIterator<Object> *)&it)->advance();
					continue;
				}
				if (flag) {
					AICommandInterface *cmd = (AICommandInterface *)((char *)ai + 0x20);
					cmd->rva0026C26D(&obj->m_38, 1);
				} else {
					if (!ai->v110()) {
						((Rva001705A0DlinkIterator<Object> *)&it)->advance();
						continue;
					}
					AISecond *sec = ai->v95();
					if (sec == 0) {
						((Rva001705A0DlinkIterator<Object> *)&it)->advance();
						continue;
					}
					sec->s11(1);
				}
				((Rva001705A0DlinkIterator<Object> *)&it)->advance();
			}
			Rva005C4AF5DwordField *gp = (Rva005C4AF5DwordField *)(base + (int)team);
			team = (Team *)pf(gp);
		}
		cur = cur->m_next;
	} while (cur != m_head);
}
