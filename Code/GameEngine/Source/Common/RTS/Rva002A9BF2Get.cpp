// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002A9BF2@Rva002A9BF2@@QAEPAXXZ @ 0x002A9BF2 (27B). Unlock lane difficulty
// getter shared by 13 callers. Evidence: GameWindow at this+0x2DC tail-jmps to
// rowed winGetUserData 0x005C4ACD when present else returns TheScriptEngine
// difficulty at global 0x009FE16C plus 0x1A4C4. Callers 0x00203F0E and
// 0x0058AF47 use ecx-this with no stack args and treat eax as int index.

class GameWindow
{
public:
	char _pad1C[0x1C];
	int m_unk1C;
	void *winGetUserData();
};

class ScriptEngine
{
public:
	char _pad[0x1A4C4];
	void *m_difficulty;
};

extern ScriptEngine *TheScriptEngine;

class Rva002A9BF2
{
	char _pad[0x2DC];
	GameWindow *m_window;
public:
	void *rva002A9BF2();
	void rva002A9CCA(int val);
};

void *Rva002A9BF2::rva002A9BF2()
{
	GameWindow *w = m_window;
	if (w != 0)
		return w->winGetUserData();
	return TheScriptEngine->m_difficulty;
}

void Rva002A9BF2::rva002A9CCA(int val)
{
	GameWindow *w = m_window;
	if (w != 0)
		w->m_unk1C = val;
}
