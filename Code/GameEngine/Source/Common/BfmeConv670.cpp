// bfmeObjDAE: matched references place it at VA 0xe18388; zero-filled at retail, sized to the
// 0x2d0-byte gap before the next known global there.
extern "C" unsigned char bfmeObjDAE[720] = { 0 };
extern "C" void bfmeDtorDAE(void *what);

void __stdcall bfmeRegisterDAE(void *obj, unsigned int size, unsigned int count, void (*dtor)(void *));

void bfmeGoDAE()
{
	bfmeRegisterDAE(bfmeObjDAE, 4, 0xb2, bfmeDtorDAE);
}
