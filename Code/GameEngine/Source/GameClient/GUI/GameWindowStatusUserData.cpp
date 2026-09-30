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

private:
	char m_pad00[0x08];
	UnsignedInt m_status;	// +0x08
	char m_pad0C[0x20];
	void *m_userData;		// +0x2C
};

UnsignedInt GameWindow::winGetStatus(void)
{
	return m_status;
}

void GameWindow::winSetUserData(void *data)
{
	m_userData = data;
}
