// ?Capture_Bone@HTreeClass@@QAEXH@Z
// partial score=0.6 date=2026-10-03
// cl: /G7 /arch:SSE /DNDEBUG /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?Capture_Bone@HTreeClass@@QAEXH@Z, retail 0x00166980 (229 bytes).
//
// BFME2 rewrote Zero Hour's per-pivot IsCaptured flag as a sorted vector of
// 36-byte captured-bone records at +0x1C (Begin/End/Capacity), the same
// member HTreeClassFree.cpp clears and HTreeClassReleaseBone.cpp erases from.
// Capture_Bone finds the insertion point by Index, overwrites an equal record
// with an identity record, otherwise inserts (or appends when past the end).
// The record is Index, identity quaternion (0,0,0,1), zero translation, and a
// false world-space flag, matching the Control_Bone record model. The vector
// helpers keep the recovered Elem36 stand-in identity so the call sites mangle
// to the rowed STLport 36-byte vector bodies.
#include <vector>

class Quaternion
{
public:
	float X, Y, Z, W;
	Quaternion() {}
	Quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}
	Quaternion &operator=(const Quaternion &q)
	{
		X = q.X; Y = q.Y; Z = q.Z; W = q.W;
		return *this;
	}
};

class Vector3
{
public:
	float X, Y, Z;
	Vector3() {}
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	Vector3 &operator=(const Vector3 &v)
	{
		X = v.X; Y = v.Y; Z = v.Z;
		return *this;
	}
};

struct Elem36
{
	int Index;
	Quaternion Rotation;
	Vector3 Translation;
	bool WorldSpace;

	Elem36() {}
	Elem36(const Elem36 &other)
		: Index(other.Index), Rotation(other.Rotation),
		  Translation(other.Translation), WorldSpace(other.WorldSpace)
	{
	}
	Elem36 &operator=(const Elem36 &other)
	{
		Index = other.Index;
		Rotation = other.Rotation;
		Translation = other.Translation;
		WorldSpace = other.WorldSpace;
		return *this;
	}
};

typedef _STL::vector<Elem36, _STL::allocator<Elem36> > Elem36Vector;

class HTreeClass
{
public:
	void Capture_Bone(int boneindex);

private:
	char Name[16];
	int NumPivots;			// +0x10
	void *Pivot;			// +0x14
	float ScaleFactor;		// +0x18
	Elem36Vector m_bones;	// +0x1C
};

// ?Capture_Bone@HTreeClass@@QAEXH@Z
void HTreeClass::Capture_Bone(int boneindex)
{
	Elem36 bone;
	bone.Index = boneindex;
	bone.WorldSpace = false;
	bone.Rotation = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	bone.Translation = Vector3(0.0f, 0.0f, 0.0f);

	Elem36 *it = m_bones.begin();
	Elem36 *end = m_bones.end();
	while (it != end && it->Index < boneindex)
		++it;
	if (it == end)
		m_bones.push_back(bone);
	else if (it->Index == boneindex)
		*it = bone;
	else
		m_bones.insert(it, bone);
}
