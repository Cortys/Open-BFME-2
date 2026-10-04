// cl: /O1 /MD /DNDEBUG
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// W3DGhostObject scene and list members, ported from Zero Hour's
// GameEngineDevice/Source/W3DDevice/GameLogic/W3DGhostObject.cpp (GeneralsMD
// tree vendored under reference/open-bfme-1/inputs/reference) onto the
// BFME 2 layout. The ZH-layout W3DGhostObject.cpp beside this file places the
// members elsewhere.
//
// BFME 2 layout, from the W3DGhostObject constructor (0x00063912) and the
// bodies below: m_parentObject +0x0C, m_partitionData +0x7C,
// m_parentSnapshots[20] +0x80, DrawableInfo +0xD0, m_nextSystem +0xE0,
// m_prevSystem +0xE4. The class carries virtual bases (vbptrs at +0x08 and
// +0xEC), which none of these members touch. W3DRenderObjectSnapshot keeps
// ZH's m_robj +0x04 and m_next +0x08. W3DGhostObjectManager keeps ZH's
// m_localPlayer +0x04, the lock flags +0x08/+0x09, m_freeModules +0x0C and
// m_usedModules +0x10. In BFME 2 removeGhostObject is no longer virtual: the
// manager vftable (0x00BC59B8) has no slot for it and reset calls it directly.

typedef int Int;
typedef bool Bool;

class RenderObjClass
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void Remove( void );																							///< slot 16
	virtual void v17();
	virtual void *Peek_Scene( void );																					///< slot 18
};

class RTS3DScene
{
public:
	virtual void v00();
	virtual void v01();
	virtual void Add_Render_Object( RenderObjClass *obj );										///< slot 2
};

class W3DDisplay
{
public:
	static RTS3DScene *m_3DScene;
};

// Draw modules: BFME 2 asks a draw module for its render object through a
// virtual (slot 49) where Zero Hour cast getObjectDrawInterface() to
// W3DModelDraw and read its render object inline.
class DrawModule
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual void v31();
	virtual void v32();
	virtual void v33();
	virtual void v34();
	virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38();
	virtual void v39();
	virtual void v40();
	virtual void v41();
	virtual void v42();
	virtual void v43();
	virtual void v44();
	virtual void v45();
	virtual void v46();
	virtual void v47();
	virtual void v48();
	virtual RenderObjClass *getRenderObject( void );													///< slot 49
};

class Drawable
{
public:
	void setFullyObscuredByShroud( Bool fullyObscured );
	DrawModule **getDrawModules( void );
};

class Object
{
public:
	Drawable *getDrawable( void ) const;
};

enum ObjectShroudStatus
{
	OBJECTSHROUD_INVALID
};

class PartitionData
{
public:
	ObjectShroudStatus getShroudedStatus( Int playerIndex );
};

class GhostObjectManager
{
public:
	virtual ~GhostObjectManager();
	inline Int getLocalPlayerIndex( void ) { return m_localPlayer; }
protected:
	Int m_localPlayer;																					///< 0x04
	Bool m_lockGhostObjects;																		///< 0x08
	Bool m_saveLockGhostObjects;																///< 0x09
};
extern GhostObjectManager *TheGhostObjectManager;

class GhostObject;
class W3DGhostObjectManager;

class W3DRenderObjectSnapshot
{
	friend class W3DGhostObject;
public:
	virtual ~W3DRenderObjectSnapshot();
protected:
	RenderObjClass *m_robj;																			///< 0x04
	W3DRenderObjectSnapshot *m_next;														///< 0x08
};

class W3DGhostObject
{
	friend class W3DGhostObjectManager;
protected:
	void removeParentObject( void );
	void restoreParentObject( void );
	void addToScene( int playerIndex );
	void removeFromScene( int playerIndex );
	void getShroudStatus( int playerIndex );
	void freeAllSnapShots( void );

	char m_unrecovered00[ 0x0C ];
	Object *m_parentObject;																			///< 0x0C
	char m_unrecovered10[ 0x7C - 0x10 ];
	PartitionData *m_partitionData;																			///< 0x7C
	W3DRenderObjectSnapshot *m_parentSnapshots[ 20 ];						///< 0x80
	char m_unrecoveredD0[ 0xE0 - 0xD0 ];
	W3DGhostObject *m_nextSystem;																///< 0xE0
	W3DGhostObject *m_prevSystem;																///< 0xE4
};

class W3DGhostObjectManager : public GhostObjectManager
{
public:
	virtual void setLocalPlayerIndex( int index );
	void removeGhostObject( GhostObject *object );
protected:
	W3DGhostObject *m_freeModules;															///< 0x0C
	W3DGhostObject *m_usedModules;															///< 0x10
};

// ------------------------------------------------------------------------------------------------
/** Remove the original object from our 3D scene*/
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::removeParentObject(void)
{

	// sanity
	if( m_parentObject == 0 )
		return;

	Drawable *draw=m_parentObject->getDrawable();

	//After we remove the unfogged object, we also disable
	//anything that should be hidden inside fog - shadow, particles, etc.
	draw->setFullyObscuredByShroud(true);

	//walk through all W3D render objects used by this object
	for (DrawModule ** dm = draw->getDrawModules(); *dm; ++dm)
	{
		RenderObjClass *robj=(*dm)->getRenderObject();
		if (robj)
		{
			robj->Remove();
		}
	}
}

// ------------------------------------------------------------------------------------------------
/** Reinsert the original object into our 3D scene*/
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::restoreParentObject(void)
{
	Drawable *draw=m_parentObject->getDrawable();
	if (!draw)
		return;

	//Notify drawable that it's okay to render its render objects again.
	draw->setFullyObscuredByShroud(false);

	//walk through all W3D render objects used by this object
	for (DrawModule ** dm = draw->getDrawModules(); *dm; ++dm)
	{
		RenderObjClass *robj=(*dm)->getRenderObject();
		//robj may be null for modules which have no render objects such
		//as for build-ups that are currently disabled.
		if (robj)
		{	//if we have a render object that's not in the scene, it must have been
			//removed by the ghost object manager, so restore it.
			if (robj->Peek_Scene() == 0)
				W3DDisplay::m_3DScene->Add_Render_Object(robj);
		}
	}
}

// ------------------------------------------------------------------------------------------------
/**Remove the dummy render objects from scene that belong to given player*/
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::removeFromScene(int playerIndex)
{
	W3DRenderObjectSnapshot *snap=m_parentSnapshots[playerIndex];

	while (snap)
	{
		snap->m_robj->Remove();
		snap=snap->m_next;
	}
}

// ------------------------------------------------------------------------------------------------
/**Add the dummy render objects to scene so player sees the correct version within the fog*/
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::addToScene(int playerIndex)
{
	W3DRenderObjectSnapshot *snap=m_parentSnapshots[playerIndex];

	while (snap)
	{
		W3DDisplay::m_3DScene->Add_Render_Object(snap->m_robj);
		snap=snap->m_next;
	}
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::getShroudStatus(int playerIndex)
{
	// BFME 2 tolerates a ghost object with no partition data
	if (m_partitionData)
		m_partitionData->getShroudedStatus(playerIndex);
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void W3DGhostObject::freeAllSnapShots(void)
{
	Int playerIndex;

	playerIndex = TheGhostObjectManager->getLocalPlayerIndex();
		if (m_parentSnapshots[playerIndex])
		{	//if we have a snapshot for this object, remove it from
			//scene.
			removeFromScene(playerIndex);

			//Restore actual objects assuming they are still alive.
			if (m_parentObject)
				restoreParentObject();

			W3DRenderObjectSnapshot *snap=m_parentSnapshots[playerIndex];
			W3DRenderObjectSnapshot *nextSnap;
			while (snap)
			{	nextSnap = snap->m_next;
				::delete snap;
				snap = nextSnap;
			}
			m_parentSnapshots[playerIndex]=0;
		}
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void W3DGhostObjectManager::removeGhostObject(GhostObject *object)
{
	if (!object)
		return;

	W3DGhostObject *mod = (W3DGhostObject *)object;

	mod->freeAllSnapShots();

	// BFME 2: only a module on the used list, and not on the free list, is moved
	W3DGhostObject *it;
	for (it = m_usedModules; it; it = it->m_nextSystem)
		if (it == mod)
			break;
	if (!it)
		return;
	for (it = m_freeModules; it; it = it->m_nextSystem)
		if (it == mod)
			break;
	if (it)
		return;

	// remove module from used list
	if( mod->m_nextSystem )
		mod->m_nextSystem->m_prevSystem = mod->m_prevSystem;
	if( mod->m_prevSystem )
		mod->m_prevSystem->m_nextSystem = mod->m_nextSystem;
	else
		m_usedModules = mod->m_nextSystem;

	// add module to free list
	mod->m_prevSystem = 0;
	mod->m_nextSystem = m_freeModules;
	if( m_freeModules )
		m_freeModules->m_prevSystem = mod;
	m_freeModules = mod;
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void W3DGhostObjectManager::setLocalPlayerIndex(int index)
{
	//Whenever we switch local players, we need to remove all ghost objects belonging
	//to another player from the map.  We then insert the current local player's
	//ghost objects into the map.

	W3DGhostObject *mod = m_usedModules;

	while (mod)
	{
		mod->removeFromScene(m_localPlayer);
		if (mod->m_parentSnapshots[index])
		{	//new player has his own snapshot
			if (!mod->m_parentSnapshots[m_localPlayer] && mod->m_parentObject)
			{	//previous player didn't have a snapshot so real object must
				//have been in the scene.  Replace it with our snapshot.
				mod->removeParentObject();
			}
			mod->addToScene(index);
		}
		//new player doesn't have a snapshot which means restore original object
		//if it was replaced by a snapshot by the previous player.
		else
		if (mod->m_parentSnapshots[m_localPlayer] && mod->m_parentObject)
			mod->restoreParentObject();

		mod=mod->m_nextSystem;
	}

	m_localPlayer = index;
}
