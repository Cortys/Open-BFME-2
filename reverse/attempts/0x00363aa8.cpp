// ?rva00363AA8@Path@@QAEHXZ
// partial score=0.89 date=2026-10-01
// cl: /O1
//
// ?rva00363AA8@Path@@QAEHXZ @0x00363AA8 (47B).
// Unlock Path waypoint scan via head +0x4 and selected node +0x10 with
// optimized links +0x8 and waypoint guard +0x20. Evidence: Path layout
// matches PathCtor 0x00363DC8 and PathRva00363DF9 (head +4 sel +10
// nextOpt +8 waypoint +20); 0x7fffffff sentinel; neighbours use /O1.

struct Coord3D
{
	float x;
	float y;
	float z;
};

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
	int rva00363AA8();

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

// ?rva00363AA8@Path@@QAEHXZ present-unmatched
int Path::rva00363AA8()
{
	PathNode *head = m_path;
	if (head != 0) {
		int max = 0x7fffffff;
		PathNode *node = m_unknown10;
		if (node != 0) {
			while (node->m_waypointID == max) {
				node = node->m_nextOptimized;
				if (node == 0) {
					return max;
				}
			}
			return node->m_waypointID;
		}
	}
	return 0x7fffffff;
}
