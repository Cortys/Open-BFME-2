// cl: /Ireference/shims/bfmelist /O1 /DNDEBUG /MD /EHs /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?LookupFocusChannelVolume@@YAMH@Z @0x0035D20C 166B.
// Per-channel focus volume: start from 1.0f, gate on TheAudio, guarded list
// copy via Rva001DC57C then multiply by each matching factor.
// Evidence: pin LookupFocusChannelVolume, caller 0x0035D2F7 regainFocus,
// callee 0x001DC57C rowed, float 1.0f via g_Va00BBB8D8.
#include <list>

class AudioManager;
extern AudioManager *TheAudio;
extern float g_Va00BBB8D8;

class Rva001DC57C
{
public:
	void rva001DC57C(_STL::list<int> *dest);
};

class FocusVolume
{
public:
	char m_pad00[0x18];
	int m_channelMask;
	char m_pad1C[4];
	float m_factor;
};

class FocusResolver
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual void s6();
	virtual FocusVolume *GetVolume();
};

struct FocusHandle
{
	char m_pad[0x10];
	FocusResolver *m_resolver;
};

float LookupFocusChannelVolume(int channel)
{
	float volume = g_Va00BBB8D8;
	int mask = 1 << channel;
	if (TheAudio == 0)
		return volume;
	_STL::list<int> ids;
	((Rva001DC57C *)TheAudio)->rva001DC57C(&ids);
	for (_STL::list<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
		FocusHandle *h = (FocusHandle *)(*it);
		if (h == 0)
			continue;
		if (h->m_resolver == 0)
			continue;
		FocusVolume *v = h->m_resolver->GetVolume();
		if (v == 0)
			continue;
		if ((v->m_channelMask & mask) == 0)
			continue;
		volume *= v->m_factor;
	}
	return volume;
}
