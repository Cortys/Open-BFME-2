// cl: /O1 /DNDEBUG /MD
//
// ?Reset_List@?$RefMultiListClass@VRenderObjClass@@@@QAEXXZ,
// retail 0x0006F2DF, 25 bytes. Dedicated TU: the peek callee lives in
// RefMultiListRenderObjPeekHead.cpp and the release callee in
// RefMultiListRenderObjRemove.cpp, so the body lives here (a TU holding a
// row must not define that row's callees).
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib/multilist.h,
// RefMultiListClass::Reset_List): drain the list through Peek_Head-gated
// Release_Head calls.

class RenderObjClass;

template <class T>
class RefMultiListClass
{
public:
	T *Peek_Head(void);
	bool Release_Head(void);
	void Reset_List(void);
};

inline void RefMultiListClass<RenderObjClass>::Reset_List(void)
{
	while (Peek_Head() != 0)
		Release_Head();
}

// Header inline that other units including the header emit as select-any
// copies, which the plain definition here collided with. The anchor keeps this
// unit's copy for the row; it is not retail code.
#pragma inline_depth(0)
// ?bfmeEmitRefMultiListRenderObjResetList@@YAXPAV?$RefMultiListClass@VRenderObjClass@@@@@Z present-unmatched
void bfmeEmitRefMultiListRenderObjResetList(RefMultiListClass<RenderObjClass> *p)
{
	p->Reset_List();
}
#pragma inline_depth()
