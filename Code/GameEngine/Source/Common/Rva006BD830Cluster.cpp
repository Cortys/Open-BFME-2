// Rva006BD830::GeometryInfo shape-run height getter, retail 0x006BD830 (108 B).
// A two-flag variant of the rowed GeometryInfo::getMaxHeightAbovePosition
// 0x006BD7C0: the same [this+0x2C, this+0x30) 0x24-stride walk, sphere
// (type 0) major radius / cylinder-box (1,2) height / +0x18 z offset, and the
// reference-returning bfmeMax select -- but the loop skips a shape unless both
// +0x20 and +0x21 are set.  The extra byte check is the whole 7-byte delta from
// the 101B sibling, so the second flag is target evidence.  No reference names
// this combination, so the method keeps an address-derived name.
typedef float Real;

inline const Real &bfmeMax(const Real &a, const Real &b)
{
	return (a > b) ? a : b;
}

enum GeometryType
{
	GEOMETRY_SPHERE = 0,
	GEOMETRY_CYLINDER,
	GEOMETRY_BOX
};

class GeometryInfo
{
public:
	Real rva006BD830(void) const;

private:
	struct BfmeShape
	{
		GeometryType m_type;					// +0x00
		Real m_height;						// +0x04
		Real m_majorRadius;					// +0x08
		unsigned char m_unmodelled_00c[0x18 - 0x0C];
		Real m_offsetZ;						// +0x18
		unsigned char m_unmodelled_01c[0x20 - 0x1C];
		bool m_enabled;						// +0x20
		bool m_secondary;					// +0x21
		unsigned char m_unmodelled_022[0x24 - 0x22];
	};

	unsigned char m_unmodelled_000[0x2C];
	BfmeShape *m_shapes;
	BfmeShape *m_shapesEnd;
};

Real GeometryInfo::rva006BD830(void) const
{
	Real best = 0.0f;

	for (const BfmeShape *shape = m_shapes; shape != m_shapesEnd; ++shape)
	{
		if (!shape->m_enabled)
			continue;
		if (!shape->m_secondary)
			continue;

		Real height = 0.0f;
		switch (shape->m_type)
		{
			case GEOMETRY_SPHERE:
				height = shape->m_majorRadius;
				break;
			case GEOMETRY_CYLINDER:
			case GEOMETRY_BOX:
				height = shape->m_height;
				break;
		}

		height += shape->m_offsetZ;
		best = bfmeMax(height, best);
	}

	return best;
}
