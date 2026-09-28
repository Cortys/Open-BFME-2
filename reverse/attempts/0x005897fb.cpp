// ?loadDockPositions@DockUpdate@@IAEXXZ
// partial score=0.97 date=2026-09-28
// ?loadDockPositions@DockUpdate@@IAEXXZ
// partial score=0.97 date=2026-09-28
// cl: /O1 /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /G7 /Ireference/shims/sweep
// stlport
//
// ?loadDockPositions@DockUpdate@@IAEXXZ, retail 0x005897FB, 270 bytes.
// Protected DockUpdate bone loader. Evidence: BFME1 donor
// reference/open-bfme-1/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/DockUpdate.cpp
// loadDockPositions with DockStart DockAction DockEnd DockWaiting bones; rowed
// ctor 0x0058A290 proves +0x24 +0x30 +0x3C +0x48 +0x4C +0x50 +0x54 layout;
// 8 callers in 0x00589909..0x0058A1A1 wait on it.
#include <limits.h>

typedef float Real;
typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

struct Coord3D
{
	Coord3D() {}
	Coord3D(const Coord3D &);
	void zero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	float x;
	float y;
	float z;
};

class Matrix3D;

enum ObjectID
{
	INVALID_ID = 0,
	FORCE_OBJECTID_TO_LONG_SIZE = 0x7fffffff
};

#include <stl/_bvector.h>

namespace _STL
{
template <>
class vector<Coord3D, allocator<Coord3D> > : public _Vector_base<Coord3D, allocator<Coord3D> >
{
public:
	__forceinline vector() : _Vector_base<Coord3D, allocator<Coord3D> >(allocator<Coord3D>()) {}

	unsigned int size() const
	{
		return (unsigned int)(_M_finish - _M_start);
	}

	Coord3D &operator[](unsigned int index)
	{
		return _M_start[index];
	}

	void insert(Coord3D *position, unsigned int count, const Coord3D &value)
	{
		_M_fill_insert(position, count, value);
	}

	void resize(unsigned int newSize, Coord3D value);
	void resize(unsigned int newSize);
	void _M_fill_insert(Coord3D *position, unsigned int count, const Coord3D &value);
	Coord3D *erase(Coord3D *first, Coord3D *last);

};

template <>
class vector<ObjectID, allocator<ObjectID> > : public _Vector_base<ObjectID, allocator<ObjectID> >
{
public:
	__forceinline vector() : _Vector_base<ObjectID, allocator<ObjectID> >(allocator<ObjectID>()) {}

	typedef _STL::__type_traits<ObjectID>::has_trivial_assignment_operator _TrivialAss;

	unsigned int size() const
	{
		return (unsigned int)(_M_finish - _M_start);
	}

	ObjectID &operator[](unsigned int index)
	{
		return _M_start[index];
	}

	void insert(ObjectID *position, unsigned int count, const ObjectID &value)
	{
		_M_fill_insert(position, count, value);
	}

	void resize(unsigned int newSize, ObjectID value);
	void resize(unsigned int newSize);
	void _M_fill_insert(ObjectID *position, unsigned int count, const ObjectID &value);
	ObjectID *erase(ObjectID *first, ObjectID *last);

};
}

typedef _STL::vector<Coord3D, _STL::allocator<Coord3D> > VecCoord3D;
typedef _STL::vector<ObjectID, _STL::allocator<ObjectID> > ObjectIDVector;
typedef _STL::vector<bool, _STL::allocator<bool> > BoolVector;

class Drawable
{
public:
	Int getPristineBonePositions(const char *boneNamePrefix, Int startIndex,
		Coord3D *positions, Matrix3D *transforms, Int maxBones, Int extra) const;
};

class Thing
{
public:
	Drawable *getDrawable() const;
};

class Object : public Thing
{
};

class ModuleData;

class BehaviorModuleBase
{
public:
	Object *getObject() const { return m_object; }

private:
	virtual void unused();
	int m_a;
	Object *m_object;
};

class BehaviorModuleOther
{
	virtual void unused();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual void update() = 0;
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;

public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
	virtual void update();
};

class DockUpdateInterface
{
public:
	virtual void dockAnchor() = 0;
};

class DockUpdate : public UpdateModule, public DockUpdateInterface
{
public:
	DockUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~DockUpdate();

	virtual void objectModuleAnchor();
	virtual void behaviorAnchor();
	virtual void updateAnchor();
	virtual void dockAnchor();

protected:
	void loadDockPositions();

private:
	Coord3D m_enterPosition;
	Coord3D m_dockPosition;
	Coord3D m_exitPosition;
	Int m_numberApproachPositions;
	Int m_numberApproachPositionBones;
	Bool m_positionsLoaded;
	VecCoord3D m_approachPositions;
	ObjectIDVector m_approachPositionOwners;
	BoolVector m_approachPositionReached;
	ObjectID m_activeDocker;
	Bool m_dockerInside;
	Bool m_dockCrippled;
	Bool m_dockOpen;
};

enum
{
	DEFAULT_APPROACH_VECTOR_SIZE = 10,
	DYNAMIC_APPROACH_VECTOR_FLAG = -1
};

class DockUpdateApproachBone : public Coord3D
{
public:
	DockUpdateApproachBone();
	~DockUpdateApproachBone();
};

// ?loadDockPositions@DockUpdate@@IAEXXZ present-unmatched
void DockUpdate::loadDockPositions()
{
	Object *obj = getObject();
	Drawable *myDrawable = obj->getDrawable();

	if (myDrawable != NULL)
	{
		myDrawable->getPristineBonePositions("DockStart", 0, &m_enterPosition, NULL, 1, 0);
		myDrawable->getPristineBonePositions("DockAction", 0, &m_dockPosition, NULL, 1, 0);
		myDrawable->getPristineBonePositions("DockEnd", 0, &m_exitPosition, NULL, 1, 0);
		if (m_numberApproachPositions != DYNAMIC_APPROACH_VECTOR_FLAG)
		{
			DockUpdateApproachBone approachBones[DEFAULT_APPROACH_VECTOR_SIZE];
			m_numberApproachPositionBones = myDrawable->getPristineBonePositions("DockWaiting", 1, (Coord3D *)approachBones, NULL, m_numberApproachPositions, 0);
			if (m_numberApproachPositions == m_approachPositions.size())
			{
				for (Int copyIndex = 0; copyIndex < m_numberApproachPositions; ++copyIndex)
				{
					Coord3D *src = (Coord3D *)&approachBones[copyIndex];
					Coord3D &slot = m_approachPositions[copyIndex];
					slot = *src;
				}
			}
		}
		else
			m_numberApproachPositionBones = 0;

		m_positionsLoaded = TRUE;
	}
}
