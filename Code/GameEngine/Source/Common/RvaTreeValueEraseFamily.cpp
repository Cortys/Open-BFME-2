// cl: /O1 /EHs /MD
//
// STLport red-black tree node erases that destroy each node's value, with the
// shape of the rowed BfmeSubEBD::bfmeEraseSubtree (53 bytes: erase the right
// subtree, destroy the value at node+0x10, free the node, walk left), plus each
// tree's 41-byte clear. Found by searching .text for those shapes with call
// displacements masked. Each erase calls only itself, one rowed value
// destructor and free (0x00030830). The value destructor gives the node's value
// type; the tree itself is not recovered, so owners are named after their erase.

extern "C" void __cdecl free(void *block);

class AsciiString;
class AudioEventRTS;
class LocomotorTemplate;
class TextureClass;
struct TreeHintRef00217D4C;
enum LocomotorSetType { RvaTreeValueEraseLocomotorSetTypeUnused };
namespace _STL
{
template <class T> class allocator;
template <class T, class A> class vector;
template <class T1, class T2> struct pair { ~pair(); };
}
template <class T> class RefCountPtr { public: ~RefCountPtr(); };
class Rva00217A37;
class Rva0022115A;
class Rva003ED68D;
class Rva0041090E;
class Rva005B3751;
template <class T> class StringBase
{
	friend class Rva00217A37;
	friend class Rva0022115A;
	friend class Rva003ED68D;
	friend class Rva0041090E;
	friend class Rva005B3751;
	~StringBase();
};

struct RvaTreeValueNode
{
	unsigned int color;
	RvaTreeValueNode *parent, *left, *right;
};

struct RvaTreeValueHead
{
	char m_pad00[4]; // +0x00
	RvaTreeValueNode *m_first; // +0x04
	RvaTreeValueHead *m_next; // +0x08
	RvaTreeValueHead *m_child; // +0x0C
};

// owner Rva00079A0C: erase 0x00079A0C (value ??1?$pair@$$CBW4LocomotorSetType@@V?$vector@PBVLocomotorTemplate@@V?$allocator@PBVLocomotorTemplate@@@_STL@@@_STL@@@_STL@@QAE@XZ), clear 0x00079C8D
typedef _STL::pair<const LocomotorSetType, _STL::vector<const LocomotorTemplate *, _STL::allocator<const LocomotorTemplate *> > > Rva00079A0CValue;
class Rva00079A0C
{
public:
	void rva00079A0C(void *node);
	void rva00079C8D();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00079A0C::rva00079A0C(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00079A0C(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00079A0CValue *>(node + 1)->~Rva00079A0CValue();
		free(node);
		node = left;
	}
}

void Rva00079A0C::rva00079C8D()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00079A0C(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

class CameraMarker { public: ~CameraMarker(); };

// owner Rva001363CC: erase 0x001363CC (value ??1CameraMarker@@QAE@XZ), clear 0x001364CE
typedef CameraMarker Rva001363CCValue;
class Rva001363CC
{
public:
	void rva001363CC(void *node);
	void rva001364CE();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva001363CC::rva001363CC(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva001363CC(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva001363CCValue *>(node + 1)->~Rva001363CCValue();
		free(node);
		node = left;
	}
}

void Rva001363CC::rva001364CE()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva001363CC(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00170AE4: erase 0x00170AE4 (value ??1?$RefCountPtr@VTextureClass@@@@QAE@XZ), clear 0x00170BAD
typedef RefCountPtr<TextureClass> Rva00170AE4Value;
class Rva00170AE4
{
public:
	void rva00170AE4(void *node);
	void rva00170BAD();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00170AE4::rva00170AE4(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00170AE4(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00170AE4Value *>(node + 1)->~Rva00170AE4Value();
		free(node);
		node = left;
	}
}

void Rva00170AE4::rva00170BAD()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00170AE4(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

class Rva00151DAB { public: ~Rva00151DAB(); };

// owner Rva00170B19: erase 0x00170B19 (value ??1Rva00151DAB@@QAE@XZ), clear 0x00170BD6
typedef Rva00151DAB Rva00170B19Value;
class Rva00170B19
{
public:
	void rva00170B19(void *node);
	void rva00170BD6();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00170B19::rva00170B19(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00170B19(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00170B19Value *>(node + 1)->~Rva00170B19Value();
		free(node);
		node = left;
	}
}

void Rva00170B19::rva00170BD6()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00170B19(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

class Rva0027EA49 { public: ~Rva0027EA49(); };

// owner Rva002177CD: erase 0x002177CD (value ??1Rva0027EA49@@QAE@XZ), clear 0x002179D9
typedef Rva0027EA49 Rva002177CDValue;
class Rva002177CD
{
public:
	void rva002177CD(void *node);
	void rva002179D9();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva002177CD::rva002177CD(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva002177CD(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva002177CDValue *>(node + 1)->~Rva002177CDValue();
		free(node);
		node = left;
	}
}

void Rva002177CD::rva002179D9()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva002177CD(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00217A02: erase 0x00217A02 (value ??1?$pair@$$CBVAsciiString@@UTreeHintRef00217D4C@@@_STL@@QAE@XZ), clear 0x00217C66
typedef _STL::pair<const AsciiString, TreeHintRef00217D4C> Rva00217A02Value;
class Rva00217A02
{
public:
	void rva00217A02(void *node);
	void rva00217C66();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00217A02::rva00217A02(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00217A02(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00217A02Value *>(node + 1)->~Rva00217A02Value();
		free(node);
		node = left;
	}
}

void Rva00217A02::rva00217C66()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00217A02(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00217A37: erase 0x00217A37 (value ??1?$StringBase@D@@AAE@XZ), clear 0x00217C8F
typedef StringBase<char> Rva00217A37Value;
class Rva00217A37
{
public:
	void rva00217A37(void *node);
	void rva00217C8F();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00217A37::rva00217A37(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00217A37(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00217A37Value *>(node + 1)->~Rva00217A37Value();
		free(node);
		node = left;
	}
}

void Rva00217A37::rva00217C8F()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00217A37(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0022115A: erase 0x0022115A (value ??1?$StringBase@D@@AAE@XZ), clear 0x00221234
typedef StringBase<char> Rva0022115AValue;
class Rva0022115A
{
public:
	void rva0022115A(void *node);
	void rva00221234();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0022115A::rva0022115A(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva0022115A(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva0022115AValue *>(node + 1)->~Rva0022115AValue();
		free(node);
		node = left;
	}
}

void Rva0022115A::rva00221234()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva0022115A(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

class Rva0022DDF4 { public: ~Rva0022DDF4(); };

// owner Rva0022E121: erase 0x0022E121 (value ??1Rva0022DDF4@@QAE@XZ), clear 0x0022E177
typedef Rva0022DDF4 Rva0022E121Value;
class Rva0022E121
{
public:
	void rva0022E121(void *node);
	void rva0022E177();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0022E121::rva0022E121(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva0022E121(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva0022E121Value *>(node + 1)->~Rva0022E121Value();
		free(node);
		node = left;
	}
}

void Rva0022E121::rva0022E177()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva0022E121(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00240CAB: erase 0x00240CAB (value ??1CameraMarker@@QAE@XZ), clear 0x0024191A
typedef CameraMarker Rva00240CABValue;
class Rva00240CAB
{
public:
	void rva00240CAB(void *node);
	void rva0024191A();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00240CAB::rva00240CAB(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00240CAB(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00240CABValue *>(node + 1)->~Rva00240CABValue();
		free(node);
		node = left;
	}
}

void Rva00240CAB::rva0024191A()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00240CAB(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva002A4281: erase 0x002A4281 (value ??1?$pair@VAsciiString@@VAudioEventRTS@@@_STL@@QAE@XZ), clear 0x002A47E1
typedef _STL::pair<AsciiString, AudioEventRTS> Rva002A4281Value;
class Rva002A4281
{
public:
	void rva002A4281(void *node);
	void rva002A47E1();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva002A4281::rva002A4281(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva002A4281(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva002A4281Value *>(node + 1)->~Rva002A4281Value();
		free(node);
		node = left;
	}
}

void Rva002A4281::rva002A47E1()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva002A4281(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva003ED68D: erase 0x003ED68D (value ??1?$StringBase@D@@AAE@XZ), clear 0x003ED6E4
typedef StringBase<char> Rva003ED68DValue;
class Rva003ED68D
{
public:
	void rva003ED68D(void *node);
	void rva003ED6E4();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva003ED68D::rva003ED68D(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva003ED68D(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva003ED68DValue *>(node + 1)->~Rva003ED68DValue();
		free(node);
		node = left;
	}
}

void Rva003ED68D::rva003ED6E4()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva003ED68D(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva0041090E: erase 0x0041090E (value ??1?$StringBase@D@@AAE@XZ), clear 0x00410A14
typedef StringBase<char> Rva0041090EValue;
class Rva0041090E
{
public:
	void rva0041090E(void *node);
	void rva00410A14();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva0041090E::rva0041090E(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva0041090E(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva0041090EValue *>(node + 1)->~Rva0041090EValue();
		free(node);
		node = left;
	}
}

void Rva0041090E::rva00410A14()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva0041090E(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva00463782: erase 0x00463782 (value ??1CameraMarker@@QAE@XZ), clear 0x00463D72
typedef CameraMarker Rva00463782Value;
class Rva00463782
{
public:
	void rva00463782(void *node);
	void rva00463D72();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva00463782::rva00463782(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva00463782(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva00463782Value *>(node + 1)->~Rva00463782Value();
		free(node);
		node = left;
	}
}

void Rva00463782::rva00463D72()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva00463782(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}

// owner Rva005B3751: erase 0x005B3751 (value ??1?$StringBase@D@@AAE@XZ), clear 0x005B3947
typedef StringBase<char> Rva005B3751Value;
class Rva005B3751
{
public:
	void rva005B3751(void *node);
	void rva005B3947();
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

void Rva005B3751::rva005B3751(void *p)
{
	RvaTreeValueNode *node = (RvaTreeValueNode *)p;
	while (node) {
		rva005B3751(node->right);
		RvaTreeValueNode *left = node->left;
		reinterpret_cast<Rva005B3751Value *>(node + 1)->~Rva005B3751Value();
		free(node);
		node = left;
	}
}

void Rva005B3751::rva005B3947()
{
	if (m_04Flag == 0)
		return;
	RvaTreeValueHead *h = (RvaTreeValueHead *)m_00Head;
	rva005B3751(h->m_first);
	((RvaTreeValueHead *)m_00Head)->m_next = (RvaTreeValueHead *)m_00Head;
	((RvaTreeValueHead *)m_00Head)->m_first = 0;
	((RvaTreeValueHead *)m_00Head)->m_child = (RvaTreeValueHead *)m_00Head;
	m_04Flag = 0;
}
