// cl: /O2 /DNDEBUG /MD /EHsc /arch:SSE
//
// Six WWLib VectorClass<T> global teardowns at 0x007B7280, 0x007B72C0,
// 0x007B7300, 0x007B7340, 0x007B7380 and 0x007B7400 (59 bytes each).
//
// Retail's body is the TU-local atexit destructor MSVC emits for a
// namespace-scope VectorClass object: store the vtable pointer, then Clear()
// inlined -- delete[] Vector through operator delete[] at 0x0002FD80, zero
// Vector, IsAllocated and VectorMax. The object layout is the vendor vector.h
// layout: vptr +0, Vector +4, VectorMax +8, IsValid +0xC, IsAllocated +0xD.
//
// Identity of the owning globals and of the T of every instantiation beyond
// the first is unproven; the globals are therefore address-named. Each global's
// VA and each distinct vtable VA below is the target's own DIR32 operand, so
// both are auto-patched from retail. The vtable data itself is not recovered --
// only its address is used -- hence the anchor blobs. The teardown bodies are
// reconstructed as the equivalent free functions (same recipe as the matched
// 40-byte chain cleanups in System/GlobalChainCleanup.cpp).
void __cdecl operator delete[](void *);

struct RvaVectorClass
{
	void *vptr;
	void *vector;
	int vectorMax;
	bool isValid;
	bool isAllocated;
};

// Zero-filled object slots. Only the teardown stubs below reference them.
RvaVectorClass g_rva00DF94D0;	// vtable VA 0x00BCEFAC (VectorClass<Vector3>)
RvaVectorClass g_rva00DF94B0;	// vtable VA 0x00BD4EB4
RvaVectorClass g_rva00DB6488;	// vtable VA 0x00BD4ECC
RvaVectorClass g_rva00DB6498;	// vtable VA 0x00BD4E9C
RvaVectorClass g_rva00DB64A8;	// vtable VA 0x00BD4E9C
RvaVectorClass g_rva00DF708C;	// vtable VA 0x00BCEFAC (VectorClass<Vector3>)

// Vtable-address anchors, one per distinct target vtable VA. The slot contents
// are not recovered; the teardown only stores the anchor's address.
void *const RvaBcefacVtable[7] = { 0 };
void *const RvaBd4eb4Vtable[7] = { 0 };
void *const RvaBd4eccVtable[7] = { 0 };
void *const RvaBd4e9cVtable[7] = { 0 };

void rva007B7280()
{
	RvaVectorClass &v = g_rva00DF94D0;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBcefacVtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}

void rva007B72C0()
{
	RvaVectorClass &v = g_rva00DF94B0;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBd4eb4Vtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}

void rva007B7300()
{
	RvaVectorClass &v = g_rva00DB6488;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBd4eccVtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}

void rva007B7340()
{
	RvaVectorClass &v = g_rva00DB6498;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBd4e9cVtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}

void rva007B7380()
{
	RvaVectorClass &v = g_rva00DB64A8;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBd4e9cVtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}

void rva007B7400()
{
	RvaVectorClass &v = g_rva00DF708C;
	void *vec = v.vector;
	v.vptr = (void *)&RvaBcefacVtable;
	if (vec != 0 && v.isAllocated) {
		operator delete[](vec);
		v.vector = 0;
	}
	v.isAllocated = false;
	v.vectorMax = 0;
}
