// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
// Open-BFME5 conversions.

class BfmeC986
{
public:
	void bfmeGo986C(int a, int b, int c, int d);
	char bfmeReady986C();
	void bfmePrep986C();
	void bfmeSend986C(int a, int b, int c, int d, int e);
};

void BfmeC986::bfmeGo986C(int a, int b, int c, int d)
{
	if (!bfmeReady986C())
		return;

	bfmePrep986C();
	bfmeSend986C(a, b, 0, c, d);
}
