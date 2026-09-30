// ??1AggregateDefClass@@UAE@XZ
// partial score=0.93 date=2026-09-30
// Follow-up: current agg_def.cpp reproduces the same 130-byte body.
// /EHs also emits 130 bytes with the same extra EH-state store.
// /EHa emits 105 bytes and changes the prologue; neither resolves the blocker.
// The five newly matched aggregate siblings do not change this EH issue.
// Partial 0.93 for ??1AggregateDefClass@@UAE@XZ @0x1A3C90 (122B).
// Donor is AggregateDefClass::~AggregateDefClass in
// Code/Libraries/Source/WWVegas/WW3D2/agg_def.cpp (ZH verbatim: free the
// name buffer, then Free_Subobject_List; the DynamicVectorClass member
// teardown comes from the ZH Vector.H inline ~VectorClass).
// Best build of the untouched donor TU is 130/122: 41/40 insns, every call
// and store matches (entry vtable BD6C70, name free via 0x30830, direct
// Free_Subobject_List, member vtable restore BD6C0C, conditional delete[]
// via 0x2FD80, null stores) except ONE 8B delta: ours emits
// `mov [esp+0x14],-1` (EH state reset, member teardown deemed nothrow)
// where retail keeps state 0 (member teardown throwing).
// Follow-up trials: /EHs retains the extra store; /EHa changes the prologue.
// Next ideas: the throwing-ness of the inline member teardown differs --
// retail's ~VectorClass/Clear chain must contain a throwing call where ours
// folds to nothrow delete[]. TU-scoped levers only (15 rows share the TU
// flags /arch:SSE /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MT /EHsc): force the
// member destruction through a throwing spelling without adding a call
// (e.g. a TU-local throwing helper in the chain is forbidden -- it would
// add bytes; instead find what makes retail's identical byte sequence
// throwing: compare try-maps/funclets of ours vs retail, or test whether
// declaring the member-dtor chain with different throw-specs changes the
// reset without changing bytes).
// Boundary: ret at +0x79, int3 pad after; vtable BD6C70 slot0 is ??_G
// 0x1A3F40 (30B, calls here) is now matched. This destructor is pinned for
// that call but remains unclaimed as an exact body; its EH delta is unresolved.
AggregateDefClass::~AggregateDefClass (void)
{
	// Free the name buffer if necessary
	if (m_pName != NULL) {

		// free() is used because the buffer was allocated with ::_strdup().
		::free (m_pName);
		m_pName = NULL;
	}

	Free_Subobject_List ();
	return ;
}
