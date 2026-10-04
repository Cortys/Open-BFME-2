// cl: /MD /Oi
//
// ProfileCmdInterface::AddResultFunction, retail 0x006C67F0 (208 bytes),
// verbatim from Zero Hour's profile_cmd.cpp (DFAIL_IF compiles to a plain
// return in this build). GetClockCyclesFast registers file_csv, file_dot and
// BFME2's file_gtt_dot through it.

extern "C" int __cdecl strcmp(const char *a, const char *b);

void *ProfileReAllocMemory(void *oldPtr, unsigned int newSize);

class ProfileResultInterface;

class ProfileCmdInterface
{
public:
	static void AddResultFunction(ProfileResultInterface *(*func)(int, const char *const *),
		const char *name, const char *arg);

private:
	struct Factory
	{
		ProfileResultInterface *(*func)(int, const char *const *);
		const char *name;
		const char *arg;
	};

	static unsigned numResIf;
	static Factory *resIf;
};

// Zero-filled .bss at 0x00E0C634 / 0x00E0C630; this function is their only
// referencing code (data_xrefs).
unsigned ProfileCmdInterface::numResIf;
ProfileCmdInterface::Factory *ProfileCmdInterface::resIf;

// ?AddResultFunction@ProfileCmdInterface@@SAXP6APAVProfileResultInterface@@HPBQBD@ZPBD2@Z
void ProfileCmdInterface::AddResultFunction(ProfileResultInterface *(*func)(int, const char *const *),
	const char *name, const char *arg)
{
	if (!func)
		return;
	if (!name)
		return;
	for (unsigned k = 0; k < numResIf; k++)
		if (!strcmp(resIf[k].name, name))
			return;
	++numResIf;
	resIf = (Factory *)ProfileReAllocMemory(resIf, numResIf * sizeof(Factory));
	resIf[numResIf - 1].func = func;
	resIf[numResIf - 1].name = name;
	resIf[numResIf - 1].arg = arg;
}
