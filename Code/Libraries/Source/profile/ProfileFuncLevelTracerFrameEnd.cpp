// cl: /MD
//
// ProfileFuncLevelTracer::FrameEnd at retail 0x006C83A0 (16B). BFME2
// replaced Zero Hour's frame-recording body with a hook gate like the one
// at 0x006C8380 (ProfileHookGate.cpp): when the global hook at [0x00E0C76C]
// is set, it is called __stdcall with (1, 0). The (which, mixIndex)
// arguments only select this gate through its Profile::StopRange caller.

class ProfileFuncLevelTracer
{
public:
	static void FrameEnd(int which, int mixIndex);
};

typedef void (__stdcall *ProfileFuncLevelHook)(int first, int second);

// g_Va00E0C76C: VA 0x00E0C76C (.data/bss); zero-filled optional hook pointer.
ProfileFuncLevelHook g_Va00E0C76C;

#define TheFuncLevelHook g_Va00E0C76C

// ?FrameEnd@ProfileFuncLevelTracer@@SAXHH@Z
void ProfileFuncLevelTracer::FrameEnd(int /*which*/, int /*mixIndex*/)
{
	if (TheFuncLevelHook != 0)
		TheFuncLevelHook(1, 0);
}
