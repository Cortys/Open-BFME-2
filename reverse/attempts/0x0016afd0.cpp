// ?rva0016AFD0@Rva0016AFD0@@QAE_NAAVChunkLoadClass@@@Z
// partial score=0.82 date=2026-10-02
// cl: /G7 /arch:SSE /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
//
// ?rva0016AFD0@Rva0016AFD0@@QAE_NAAVChunkLoadClass@@@Z @0x0016AFD0 72B.
// Bulk vertex-chunk reader: Resize the ShareBuffer<Vector3> vertex store at
// +0x44 to the VertexCount at +0x28 then single ChunkLoadClass::Read of
// count*sizeof(Vector3) bytes; returns read == expected. Evidence: rowed
// Resize 0x00169470 and Read 0x006151A0 callees, caller at 0x0018B91E,
// MeshGeometryClass neighbours (Compute_Ram_Size, read_triangles) with the
// +0x28 count and +0x40/+0x44 buffers, honest address name since no vtable
// or claimant proves the owner.
#include "always.h"
#include "refcount.h"
#include "bittype.h"
#include "chunkio.h"

class Vector3
{
public:
	float x, y, z;
	Vector3() {}
};

template<class T>
class ShareBufferClass : public RefCountClass
{
public:
	void Resize(int newsize);
	T *Get_Array(void) { return Array; }
protected:
	T *RawBuffer;
	T *Array;
	int Count;
	int Alignment;
};

class Rva0016AFD0
{
public:
	bool rva0016AFD0(ChunkLoadClass &cload);
private:
	virtual ~Rva0016AFD0();
	char m_pad04[0x28 - 0x4];
	int m_count28;
	char m_pad2C[0x44 - 0x2C];
	ShareBufferClass<Vector3> *m_vertex44;
};

// ?rva0016AFD0@Rva0016AFD0@@QAE_NAAVChunkLoadClass@@@Z present-unmatched
bool Rva0016AFD0::rva0016AFD0(ChunkLoadClass &cload)
{
	ShareBufferClass<Vector3> *vertex = m_vertex44;
	if (vertex == 0)
		return false;
	int count = m_count28;
	vertex->Resize(count);
	Vector3 *buf = vertex->Get_Array();
	if (buf == 0)
		return false;
	unsigned long size = (unsigned long)count * sizeof(Vector3);
	return cload.Read(buf, size) == size;
}
