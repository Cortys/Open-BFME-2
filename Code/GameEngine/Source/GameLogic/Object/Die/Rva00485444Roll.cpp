// cl: /O1 /MD /arch:SSE
//
// ?Rva00485444Roll@@YGHPAX@Z, retail 0x00485444 60B: chance roll vs random 0..1.
// Evidence: free stdcall ret 4 with rowed GetGameLogicRandomValueReal 0x00234092 plus float at +0x14; caller 0x0048583A.

float __cdecl GetGameLogicRandomValueReal(float lo, float hi, char *file, int line);

int __stdcall Rva00485444Roll(void *a)
{
	float chance = *(float *)((char *)a + 0x14);
	float r = GetGameLogicRandomValueReal(0.0f, 1.0f, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\Object\\Die\\CreateCrateDie.cpp", 0x70);
	if (chance > r)
		return 1;
	return 0;
}
