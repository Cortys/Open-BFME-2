// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
//
// retail 0x00069130, 22 bytes. The sweep lists this RVA twice: once against
// game/GameEngineDevice/Source/W3DDevice/GameClient/BaseHeightMapConstructor.cpp,
// where ?pow is only a header declaration the compiler emitted there, and once
// against this donor, which defines bfmeGoTKD out-of-line. land.py refuses the
// first because it is not a definition of that file. The out-of-line copy is
// the one recovered here; the donor's other body (the BfmeThingTKB constructor)
// is omitted.
void bfmeStepTKD(double d, int a);

void bfmeGoTKD(double d, int a)
{
	bfmeStepTKD(d, a);
}
