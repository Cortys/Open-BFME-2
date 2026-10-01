// ?rva00363EC0@Path@@QAEMPAUCoord3D@@0@Z
// partial score=0.99 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva00363EC0@Path@@QAEMPAUCoord3D@@0@Z @0x00363EC0 (228B).
// Unlock Path projection via head +0x4 with optimized links +0x8 and
// waypoint-style accumulation. Evidence: neighbours PathRva00363DF9
// 0x00363DF9 and PathRva003649B1 prove Path/PathNode layout and
// /O1 /arch:SSE flags; rowed Coord2D::normalize at 0x0000378A;
// BfmeZeroRange extern; EAX holds out pattern suggests Path method.

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Coord2D
{
public:
	void normalize();

	float x;
	float y;
};

extern const float BfmeZeroRange;

class PathNode
{
public:
	PathNode *m_next;
	PathNode *m_previous;
	PathNode *m_nextOptimized;
	Coord3D m_position;
	int m_layer;
	bool m_canOptimize;
	int m_waypointID;
};

class Path
{
public:
	float rva00363EC0(Coord3D *p, Coord3D *out);

private:
	void *m_unknown00;
	PathNode *m_path;
	PathNode *m_pathTail;
	bool m_isOptimized;
	bool m_unknown0D;
	PathNode *m_unknown10;
	float m_unknown14;
	float m_unknown18;
	float m_unknown1C;
	float m_unknown20;
	int m_unknown24;
};

// ?rva00363EC0@Path@@QAEMPAUCoord3D@@0@Z present-unmatched
float Path::rva00363EC0(Coord3D *p, Coord3D *out)
{
	PathNode *head = m_path;
	if (head == 0) {
		float ret = BfmeZeroRange;
		out->x = 0.0f;
		out->y = 0.0f;
		out->z = 0.0f;
		return ret;
	}
	PathNode *node = head->m_nextOptimized;
	*out = head->m_position;
	float acc = 0.0f;
	bool first = true;
	PathNode *prev = head;
	while (node != 0) {
		if (first) {
			*out = node->m_position;
		}
		Coord2D d1;
		d1.x = node->m_position.x - p->x;
		d1.y = node->m_position.y - p->y;
		Coord2D d2;
		d2.x = node->m_position.x - prev->m_position.x;
		d2.y = node->m_position.y - prev->m_position.y;
		d2.normalize();
		float dot = d2.y * d1.y + d2.x * d1.x;
		if (dot >= BfmeZeroRange) {
			acc += dot;
			first = false;
		}
		prev = node;
		node = node->m_nextOptimized;
	}
	return acc;
}
