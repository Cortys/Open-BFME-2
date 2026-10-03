// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /D_STLP_NO_EXCEPTIONS
// stlport
#include <vector>

struct Rva0042464E
{
	char m_pad[0xC];
	~Rva0042464E();
};

struct LightSubPoint
{
	Rva0042464E m_vec1;
	_STL::vector<int> m_vec2;
	~LightSubPoint();
};

LightSubPoint::~LightSubPoint()
{
}

class LightPoint
{
public:
	_STL::vector<LightSubPoint> m_points;
	~LightPoint();
};

LightPoint::~LightPoint()
{
}

// ?anchorDeleteLightPoint@@YAXPAVLightPoint@@@Z present-unmatched
void anchorDeleteLightPoint(LightPoint *p)
{
	delete p;
}
