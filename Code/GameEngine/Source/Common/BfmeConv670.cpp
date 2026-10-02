// bfmeObjDAE: matched references place it at VA 0xe18388; zero-filled at retail, sized to the
// 0x2d0-byte gap before the next known global there.
extern "C" unsigned char bfmeObjDAE[720] = { 0 };
extern "C" void bfmeDtorDAE(void *what);

void __stdcall bfmeRegisterDAE(void *obj, unsigned int size, unsigned int count, void (*dtor)(void *));

void bfmeGoDAE()
{
	bfmeRegisterDAE(bfmeObjDAE, 4, 0xb2, bfmeDtorDAE);
}

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
#pragma comment(linker, "/alternatename:?bfmeRegisterDAE@@YGXPAXIIP6AX0@Z@Z=??_M@YGXPAXIHP6EX0@Z@Z")
