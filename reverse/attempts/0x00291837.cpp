// ?rva00291837@Object@@QAE_NXZ
// partial score=0.9 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /MD
// ?rva00291837@Object@@QAE_NXZ @ 0x00291837 (60B) unlock: command-button 0x20 flag scan over 32 slots via rowed Object name plus rowed Rva0031D5F8 lookup plus pinned getCommandButton. Evidence: caller 0x0030F027 thiscall no args bool return on Object; g_bfmeWorldRV; +0x1E test 0x20; sibling Rva002917E8Check.
#include "ascii_string.h"

struct BfmeWorldRV;
extern struct BfmeWorldRV *g_bfmeWorldRV;

class Object
{
public:
	const AsciiString *rva00290E67(void) const;
	bool rva00291837(void);
};

class Rva0031D5F8
{
public:
	void *rva0031D5F8(const AsciiString *);
};

class CommandButton
{
public:
	char m_pad[0x1E];
	unsigned char m_flag1E;
};

class CommandSet
{
public:
	const CommandButton *getCommandButton(int) const;
};

// ?rva00291837@Object@@QAE_NXZ present-unmatched
bool Object::rva00291837(void)
{
	const AsciiString *name = rva00290E67();
	const CommandSet *cmdSet = (const CommandSet *)((Rva0031D5F8 *)g_bfmeWorldRV)->rva0031D5F8(name);
	if (cmdSet) {
		for (int i = 0; i < 0x20; i++) {
			const CommandButton *btn = cmdSet->getCommandButton(i);
			if (btn && (btn->m_flag1E & 0x20))
				return true;
		}
	}
	return false;
}
