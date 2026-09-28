// cl: /O1 /arch:SSE /MD /EHsc
// ??0Rva0055A246@@QAE@XZ @ 0x0055A246, 56 bytes.
// Default ctor for 4x12-byte array holder: array-new via empty Coord3D
// ctor/dtor then zero 12 floats. Evidence: ??_L call pushes size 0xC count 4
// ctor 0x47A6A9 dtor 0xB3FD0 both rowed empty folds for Coord3D; zero loop
// push-4-pop-ecx plus xorps-movss matches retail; caller 0x5C76CD passes
// this+8 and zeroes surrounding ints/floats.
class Coord3D
{
public:
	Coord3D();
	~Coord3D();
	float x;
	float y;
	float z;
};

class Rva0055A246
{
public:
	Rva0055A246();
	Coord3D m_arr[4];
};

Rva0055A246::Rva0055A246()
{
	for (int i = 0; i < 4; ++i) {
		m_arr[i].x = 0.0f;
		m_arr[i].y = 0.0f;
		m_arr[i].z = 0.0f;
	}
}
