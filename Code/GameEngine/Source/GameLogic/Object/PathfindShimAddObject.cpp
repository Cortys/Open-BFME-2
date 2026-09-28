// cl: /O1 /DNDEBUG /MD /EHsc
// ?addObjectToPathfindMap@BFMEPathfinderMapShim@@QAEXPAVObject@@@Z @0x002E7178
// ?rva002E718A@BFMEPathfinderMapShim@@QAEXPAVObject@@@Z @0x002E718A 17B: adjacent sibling
// Shard TU: friend_notifyOfNewMapBoundary lives in
// Object_friendNotifyOfNewMapBoundary.cpp under /Oy- frames; this frameless
// leaf needs no frame so it lives here. Second body abuts first and forwards
// to same helper with 0 0 0 vs 1 0 0; same class proven by adjacency and shape.

class Object;

void __stdcall Rva00530212Helper(Object *object, int a1, int a2, int a3);

class BFMEPathfinderMapShim
{
public:
	void addObjectToPathfindMap(Object *object);
	void rva002E718A(Object *object);
	void rva002E719B(Object *object);
};

// ?addObjectToPathfindMap@BFMEPathfinderMapShim@@QAEXPAVObject@@@Z
void BFMEPathfinderMapShim::addObjectToPathfindMap(Object *object)
{
	Rva00530212Helper(object, 1, 0, 0);
}

void BFMEPathfinderMapShim::rva002E718A(Object *object)
{
	Rva00530212Helper(object, 0, 0, 0);
}

void BFMEPathfinderMapShim::rva002E719B(Object *object)
{
	Rva00530212Helper(object, 0, 0, 1);
}
