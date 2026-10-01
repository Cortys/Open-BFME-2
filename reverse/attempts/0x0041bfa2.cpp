// ?rva0041BFA2@Rva0041BFA2@@QAEHPAVObject@@HHH@Z
// partial score=0.96 date=2026-10-01
// cl: /O1 /G7 /MD
// ?rva0041BFA2@Rva0041BFA2@@QAEHPAVObject@@HHH@Z @0x0041BFA2 95B
// Evidence: caller 0x0041C746; rowed testStatus 0x0004E536; Vis slot 0x110 on Object+0x250; callback code 0x0081B918.

enum ObjectStatusTypes
{
	STATUS_1 = 1
};

struct ScanArgs;
class Rva0041BFA2;

struct ScanArgs
{
	int m_out;
	Rva0041BFA2 *m_self;
	int m_a;
	int m_b;
	int m_c;
};

extern const void *const g_0081B918[];

class VisIface
{
public:
	virtual void d00();
	virtual void d01();
	virtual void d02();
	virtual void d03();
	virtual void d04();
	virtual void d05();
	virtual void d06();
	virtual void d07();
	virtual void d08();
	virtual void d09();
	virtual void d10();
	virtual void d11();
	virtual void d12();
	virtual void d13();
	virtual void d14();
	virtual void d15();
	virtual void d16();
	virtual void d17();
	virtual void d18();
	virtual void d19();
	virtual void d20();
	virtual void d21();
	virtual void d22();
	virtual void d23();
	virtual void d24();
	virtual void d25();
	virtual void d26();
	virtual void d27();
	virtual void d28();
	virtual void d29();
	virtual void d30();
	virtual void d31();
	virtual void d32();
	virtual void d33();
	virtual void d34();
	virtual void d35();
	virtual void d36();
	virtual void d37();
	virtual void d38();
	virtual void d39();
	virtual void d40();
	virtual void d41();
	virtual void d42();
	virtual void d43();
	virtual void d44();
	virtual void d45();
	virtual void d46();
	virtual void d47();
	virtual void d48();
	virtual void d49();
	virtual void d50();
	virtual void d51();
	virtual void d52();
	virtual void d53();
	virtual void d54();
	virtual void d55();
	virtual void d56();
	virtual void d57();
	virtual void d58();
	virtual void d59();
	virtual void d60();
	virtual void d61();
	virtual void d62();
	virtual void d63();
	virtual void d64();
	virtual void d65();
	virtual void d66();
	virtual void d67();
	virtual void scan(const void *cb, ScanArgs *args, int flag);
};

class Object
{
public:
	bool testStatus(ObjectStatusTypes st) const;
public:
	char m_pad00[0x250];
	VisIface *m_vis;
};

class Rva0041BFA2
{
public:
	int rva0041BFA2(Object *obj, int a, int b, int c);
};

// ?rva0041BFA2@Rva0041BFA2@@QAEHPAVObject@@HHH@Z present-unmatched
int Rva0041BFA2::rva0041BFA2(Object *obj, int a, int b, int c)
{
	if (obj->testStatus(STATUS_1))
	{
		VisIface *vis = obj->m_vis;
		if (vis != 0)
		{
			ScanArgs args;
			args.m_out = 0;
			args.m_a = a;
			args.m_b = b;
			args.m_self = this;
			args.m_c = c | 0x10;
			vis->scan((const void *)g_0081B918, &args, 1);
			return args.m_out;
		}
	}
	return 0;
}
