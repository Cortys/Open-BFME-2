// cl: /DNDEBUG /MD /EHsc /O2 /Ob2 /G6 /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/shims/moduledata
// stlport
// Open-BFME: GeometryInfo::calcBoundingStuff, target 0x006BE700, 301 bytes.
// BFME 1 address labels below preserve donor naming; target helpers are
// planar 0x006BE5A0 / sphere 0x006BE610 / bounds 0x006BDEE0.
//
// Identity: the matched GeometryInfo::parseGeometryIsSmall (0x0087F160)
// tail-calls this body (jmp at +0x1B) on the INI store, and the matched
// parseGeometryHeight (0x0087F180) calls it and then calls 0x0087EBB0.
// It rebuilds the bounding circle (+0x10) and sphere (+0x14) radii as the
// maximum over the enabled 0x24-byte GeometryShape entries at +0x2C, then
// derives the centre and two extents from the bounds helper at 0x0087E650.
//
// The two per-shape radius helpers (0x0087ED00, 0x0087ED70) precede this body
// in the same retail TU and are given their bodies here under noinline: retail
// keeps the shape pointer in EDX across both calls, which MSVC 7.1 only does
// when it can see the callee does not clobber EDX.  Their method names are not
// proven, so they keep their addresses.

#include <vector>
#include "coord.h"
#include "ascii_string.h"
#include "Common/Snapshot.h"

enum GeometryType
{
	GEOMETRY_SPHERE = 0,
	GEOMETRY_CYLINDER,
	GEOMETRY_BOX
};

inline Real sqr(Real x)
{
	return x * x;
}

template <class T>
inline const T &bfmeMax(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

struct GeometryShape
{
	GeometryType m_type;
	Real m_height;
	Real m_majorRadius;
	Real m_minorRadius;
	Coord3D m_offset;
	AsciiString m_name;
	Bool m_enabled;
	char m_unmodelled21[3];

	Real rva0087ED00() const;
	Real rva0087ED70() const;
};

typedef char GeometryShape_size_check[sizeof(GeometryShape) == 0x24 ? 1 : -1];

// Six-float bounds the 0x0087E650 helper fills: minimum x/y/z then maximum x/y/z.
struct Rva0087E650Bounds
{
	Coord3D lo, hi;
};
typedef char GeometryBounds_size_check[sizeof(Rva0087E650Bounds) == 24 ? 1 : -1];

template <class T>
inline const T &bfmeMin(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

class GeometryInfo : public Snapshot
{
public:
	void rva0087E650(Rva0087E650Bounds *bounds);

private:
	void calcBoundingStuff();

	Bool m_isSmall;
	int m_scalar08;
	int m_scalar0c;
	Real m_boundingCircleRadius;
	Real m_boundingSphereRadius;
	Coord3D m_boundsCenter18;
	Real m_extent24;
	Real m_extent28;
	std::vector<GeometryShape> m_shapes;
};

// ?rva0087ED00@GeometryShape@@QBEMXZ
// Target 0x006BE5A0: Ghidra boundary 101 bytes; matched caller 0x006BE72C
// folds this per-shape planar reach into the bounding-circle radius. The
// BFME 1 model supplies the sphere/cylinder/box formulas. Target evidence
// adds the copied coordinate local and separate sphere/cylinder branches:
// MSVC merges the latter and reproduces the 16-byte frame and x87 stack.
// The original method name remains unproven; the donor address labels it.
__declspec(noinline) Real GeometryShape::rva0087ED00() const
{
	Coord3D offset = {m_offset.x, m_offset.y, m_offset.z};
	Real result = 0.0f;
	switch (m_type)
	{
		case GEOMETRY_SPHERE:
			result = sqrt(sqr(offset.x) + sqr(offset.y)) + m_majorRadius;
			break;
		case GEOMETRY_CYLINDER:
			result = sqrt(sqr(offset.x) + sqr(offset.y)) + m_majorRadius;
			break;
		case GEOMETRY_BOX:
			result = sqrt(sqr(fabs(offset.x) + m_majorRadius) + sqr(fabs(offset.y) + m_minorRadius));
			break;
	}
	return result;
}

// ?rva0087ED70@GeometryShape@@QBEMXZ
// Target 0x006BE610: Ghidra boundary 228 bytes; the matched caller at
// 0x006BE74F passes an enabled 0x24-byte GeometryShape. Its sphere/cylinder/
// box paths read the type and dimensions at +0/+4/+8/+0C and offset at +10.
// BFME 1 GeometryShapeRva0087ED70.cpp at 10af19f44a89ab7ecc23195bb9a842ceafbc02c9
// supplies the named extent locals and cylinder accumulation order. These
// preserve the native x87 shape under the existing flags; full bytes match.
// The original method name remains unproven; the donor address labels it.
__declspec(noinline) Real GeometryShape::rva0087ED70() const
{
	Real result = 0.0f;
	switch (m_type)
	{
		case GEOMETRY_SPHERE:
			result = sqrt(sqr(m_offset.x) + sqr(m_offset.y) + sqr(m_offset.z)) + m_majorRadius;
			break;

		case GEOMETRY_CYLINDER:
		{
			Real planar = sqrt(sqr(m_offset.x) + sqr(m_offset.y)) + m_majorRadius;
			Real vertical = fabs(m_offset.z) + m_height * 0.5;
			Real offsetLength = sqrt(sqr(m_offset.x) + sqr(m_offset.y) + sqr(m_offset.z));
			planar = sqr(planar);
			planar += sqr(vertical);
			result = sqrt(planar) + offsetLength;
			break;
		}

		case GEOMETRY_BOX:
		{
			Real x = fabs(m_offset.x) + m_majorRadius;
			Real y = fabs(m_offset.y) + m_minorRadius;
			Real z = fabs(m_offset.z) + m_height * 0.5;
			result = sqrt((sqr(x) + sqr(y)) + sqr(z));
			break;
		}
	}
	return result;
}

// ?calcBoundingStuff@GeometryInfo@@AAEXXZ
void GeometryInfo::calcBoundingStuff()
{
	m_boundingCircleRadius = 0.01f;
	m_boundingSphereRadius = 0.0f;

	for (std::vector<GeometryShape>::const_iterator it = m_shapes.begin(); it != m_shapes.end(); ++it)
	{
		if (!it->m_enabled)
			continue;
		m_boundingCircleRadius = bfmeMax(m_boundingCircleRadius, it->rva0087ED00());
		m_boundingSphereRadius = bfmeMax(m_boundingSphereRadius, it->rva0087ED70());
	}

	Rva0087E650Bounds bounds;
	rva0087E650(&bounds);
	m_boundsCenter18.zero();
	m_boundsCenter18.x = (bounds.hi.x + bounds.lo.x) * 0.5f;
	m_boundsCenter18.y = (bounds.hi.y + bounds.lo.y) * 0.5f;
	m_boundsCenter18.z = (bounds.hi.z + bounds.lo.z) * 0.5f;
	m_extent24 = bfmeMax(bounds.hi.x, -bounds.lo.x);
	m_extent28 = bfmeMax(bounds.hi.y, -bounds.lo.y);
}

// ?rva0087E650@GeometryInfo@@QAEXPAURva0087E650Bounds@@@Z
// Target 0x006BDEE0: Ghidra boundary 636 bytes. Matched caller 0x006BE782
// independently establishes this GeometryInfo owner and a six-float bounds
// output; the target traverses enabled 0x24-byte shapes at receiver +0x2C.
// BFME 1 GeometryInfoRva0087E650.cpp at 10af19f44a89ab7ecc23195bb9a842ceafbc02c9
// supplies the min/max structure and scalar control flow. The BFME 1
// address is folded, so it cannot establish an original method name.
// Coord3D::zero on each half reproduces the native clear; full bytes match.
void GeometryInfo::rva0087E650(Rva0087E650Bounds *bounds)
{
	bounds->lo.zero();
	bounds->hi.zero();

	for (std::vector<GeometryShape>::const_iterator it = m_shapes.begin(); it != m_shapes.end(); ++it)
	{
		if (!it->m_enabled)
			continue;

		switch (it->m_type)
		{
		case GEOMETRY_SPHERE:
			bounds->lo.x = bfmeMin(bounds->lo.x, it->m_offset.x - it->m_majorRadius);
			bounds->lo.y = bfmeMin(bounds->lo.y, it->m_offset.y - it->m_majorRadius);
			bounds->lo.z = bfmeMin(bounds->lo.z, it->m_offset.z - it->m_majorRadius);
			bounds->hi.x = bfmeMax(bounds->hi.x, it->m_offset.x + it->m_majorRadius);
			bounds->hi.y = bfmeMax(bounds->hi.y, it->m_offset.y + it->m_majorRadius);
			bounds->hi.z = bfmeMax(bounds->hi.z, it->m_offset.z + it->m_majorRadius);
			break;
		case GEOMETRY_CYLINDER:
			bounds->lo.x = bfmeMin(bounds->lo.x, it->m_offset.x - it->m_majorRadius);
			bounds->lo.y = bfmeMin(bounds->lo.y, it->m_offset.y - it->m_majorRadius);
			bounds->lo.z = bfmeMin(bounds->lo.z, it->m_offset.z);
			bounds->hi.x = bfmeMax(bounds->hi.x, it->m_offset.x + it->m_majorRadius);
			bounds->hi.y = bfmeMax(bounds->hi.y, it->m_offset.y + it->m_majorRadius);
			bounds->hi.z = bfmeMax(bounds->hi.z, it->m_offset.z + it->m_height);
			break;
		case GEOMETRY_BOX:
			bounds->lo.x = bfmeMin(bounds->lo.x, it->m_offset.x - it->m_majorRadius);
			bounds->lo.y = bfmeMin(bounds->lo.y, it->m_offset.y - it->m_minorRadius);
			bounds->lo.z = bfmeMin(bounds->lo.z, it->m_offset.z);
			bounds->hi.x = bfmeMax(bounds->hi.x, it->m_offset.x + it->m_majorRadius);
			bounds->hi.y = bfmeMax(bounds->hi.y, it->m_offset.y + it->m_minorRadius);
			bounds->hi.z = bfmeMax(bounds->hi.z, it->m_offset.z + it->m_height);
			break;
		}
	}
}
