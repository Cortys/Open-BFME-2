// cl: /O1
//
// GameWindow::winGetStatus (retail 0x0030F45F, 4 bytes) and
// GameWindow::winSetUserData (retail 0x002B2210, 10 bytes): Zero Hour
// GameWindow.cpp accessors of m_status (+0x08, the offset GameWindowHide.cpp's
// rowed winSetStatus/winHide use) and m_userData (+0x2C, the offset the rowed
// winGetUserData reads). The GUI units that call them pin both names at these
// addresses. Retail folded each with an identical one-instruction accessor:
// winGetStatus lands as the ICF alias of the rowed
// CategoryModuleClass<1>::getName; winSetUserData replaces a gen-alias
// placeholder (Matrix3D::Set_Z_Translation's identical bytes).

typedef unsigned int UnsignedInt;

class GameWindow
{
public:
	UnsignedInt winGetStatus(void);
	void winSetUserData(void *data);
	UnsignedInt winGetStyle(void);
	GameWindow *winGetParent(void);
	GameWindow *winGetChild(void);

private:
	char m_pad00[0x08];
	UnsignedInt m_status;	// +0x08
	char m_pad0C[0x20];
	void *m_userData;		// +0x2C
	char m_pad30[0x0C];
	UnsignedInt m_style;	// +0x3C
	char m_pad40[0x1C0];
	GameWindow *m_parent;	// +0x200
	GameWindow *m_child;	// +0x204
};

UnsignedInt GameWindow::winGetStatus(void)
{
	return m_status;
}

void GameWindow::winSetUserData(void *data)
{
	m_userData = data;
}

// winGetStyle (0x005C4AF1, +0x3C), winGetParent (0x003140A4, +0x200) and
// winGetChild (0x003140C8, +0x204): pinned at those addresses by the GUI
// callers; m_parent and m_child are adjacent as in Zero Hour's GameWindow.h.
// Each is folded with an identical one-load getter already rowed there.
UnsignedInt GameWindow::winGetStyle(void)
{
	return m_style;
}

GameWindow *GameWindow::winGetParent(void)
{
	return m_parent;
}

GameWindow *GameWindow::winGetChild(void)
{
	return m_child;
}
