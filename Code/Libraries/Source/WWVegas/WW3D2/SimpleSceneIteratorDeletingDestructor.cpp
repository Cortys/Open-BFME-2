// cl: /DNDEBUG /MD /EHsc

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2/scene.h
class SceneIterator
{
public:
	virtual ~SceneIterator() {}
};

class RenderObjClass;

template <class T> class RefMultiListClass
{
public:
	void *m_unused[2];
	void *m_first;
};

class SimpleSceneIterator : public SceneIterator
{
public:
	virtual ~SimpleSceneIterator();

protected:
	SimpleSceneIterator(RefMultiListClass<RenderObjClass> *render_list);

private:
	RefMultiListClass<RenderObjClass> *m_render_list;
	void *m_current;
};

inline __declspec(noinline) SimpleSceneIterator::SimpleSceneIterator(
	RefMultiListClass<RenderObjClass> *render_list) :
	m_render_list(render_list),
	m_current(render_list->m_first)
{
}

__declspec(noinline) SimpleSceneIterator::~SimpleSceneIterator() {}

void Force_SimpleSceneIterator_Deleting_Destructor(SimpleSceneIterator *iterator)
{
	delete iterator;
}

// SimpleSceneIterator ctor is a header inline elsewhere: another unit emits a
// select-any copy, so a strong definition here was a duplicate symbol in the
// linked build. This anchor only makes this unit emit its copy for the ledger
// row; it is not retail code.
struct BfmeSimpleSceneIteratorEmitter : SimpleSceneIterator
{
	static void emit(BfmeSimpleSceneIteratorEmitter *p, RefMultiListClass<RenderObjClass> *list);
};
#pragma inline_depth(0)
// ?emit@BfmeSimpleSceneIteratorEmitter@@SAXPAU1@PAV?$RefMultiListClass@VRenderObjClass@@@@@Z present-unmatched
void BfmeSimpleSceneIteratorEmitter::emit(BfmeSimpleSceneIteratorEmitter *p, RefMultiListClass<RenderObjClass> *list)
{
	p->SimpleSceneIterator::SimpleSceneIterator(list);
}
#pragma inline_depth()
