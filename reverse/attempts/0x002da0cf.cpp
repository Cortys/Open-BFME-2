// ?rva002DA0CF@Rva002DA0CF@@QAENXZ
// partial score=0.97 date=2026-10-01
// ?rva002DA0CF@Rva002DA0CF@@QAENXZ
// partial score=0.97 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva002DA0CF@Rva002DA0CF@@QAENXZ @0x002DA0CF 132B: float thiscall with
// state at +0x38 selecting GameLogic/GameClient early-zero vs float path.
// Evidence: findObjectByID 0x00049DC5; TheGameLogic 0x009FE78C; TheGameClient
// 0x009FE77C with virtual at +0x40 and byte at +0x44a; BfmeZeroRange
// 0x007BAEAC; g_00BBB9AC float compare; g_00BC26F8 double mul; caller
// 0x00059B0A.
enum ObjectID
{
	INVALID_OBJECT_ID = 0
};

class Object;

class GameLogic
{
public:
	Object *findObjectByID(ObjectID id);
};

extern GameLogic *TheGameLogic;
extern const float BfmeZeroRange;
extern float g_00BBB9AC;
extern double g_00BC26F8;

struct ClientRet40
{
	char m_pad[0x44a];
	unsigned char m_44a;
};

class ClientFrameSubsystem
{
public:
	virtual void s000();
	virtual void s001();
	virtual void s002();
	virtual void s003();
	virtual void s004();
	virtual void s005();
	virtual void s006();
	virtual void s007();
	virtual void s008();
	virtual void s009();
	virtual void s010();
	virtual void s011();
	virtual void s012();
	virtual void s013();
	virtual void s014();
	virtual void s015();
	virtual ClientRet40 *s016(int id);
};

extern ClientFrameSubsystem *TheGameClient;

struct Sub08
{
	char m_pad[0x10];
	float m_10;
};

class Rva002DA0CF
{
public:
	double rva002DA0CF();
private:
	char m_pad00[0x08];
	Sub08 *m_08;
	char m_pad0C[0x24 - 0x0C];
	float m_24;
	char m_pad28[0x2C - 0x24 - 4];
	float m_2C;
	char m_pad30[0x34 - 0x30];
	int m_34;
	int m_38;
};

// ?rva002DA0CF@Rva002DA0CF@@QAENXZ present-unmatched
double Rva002DA0CF::rva002DA0CF()
{
	switch (m_38) {
		case 2: {
			Object *obj = TheGameLogic->findObjectByID((ObjectID)m_34);
			if (obj == 0)
				break;
			unsigned int v = *(unsigned int *)((char *)obj + 0x98);
			v >>= 0x14;
			unsigned char b = (unsigned char)~(unsigned char)v;
			if (b & 1)
				break;
			return BfmeZeroRange;
		}
		case 1: {
			ClientRet40 *p = TheGameClient->s016(m_34);
			if (p == 0)
				break;
			if (p->m_44a != 0)
				break;
			return BfmeZeroRange;
		}
		default:
			break;
	}
floatPath:
	if (m_24 == g_00BBB9AC) {
		if (m_08 != 0)
			return m_08->m_10 * m_2C;
		return m_2C * g_00BC26F8;
	}
	return m_2C * m_24;
}
