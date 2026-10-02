// ?rva0016AF80@Rva0016AF80@@QAE_NAAVChunkLoadClass@@@Z
// partial score=0.82 date=2026-10-02
// cl: /G7 /arch:SSE /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
//
// ?rva0016AF80@Rva0016AF80@@QAE_NAAVChunkLoadClass@@@Z @0x0016AF80 72B.
// Bulk vertex-chunk reader sibling of 0x0016AFD0: Resize the ShareBuffer<Vector3>
// store at +0x40 to the VertexCount at +0x28 then single ChunkLoadClass::Read;
// returns read == expected. Evidence: rowed Resize 0x00169470 and Read 0x006151A0,
// caller at 0x0018B8F7, same MeshGeometryClass neighbours, honest address name.
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

class Rva0016AF80
{
public:
	bool rva0016AF80(ChunkLoadClass &cload);
private:
	virtual ~Rva0016AF80();
	char m_pad04[0x28 - 0x4];
	int m_count28;
	char m_pad2C[0x40 - 0x2C];
	ShareBufferClass<Vector3> *m_vertex40;
};

// ?rva0016AF80@Rva0016AF80@@QAE_NAAVChunkLoadClass@@@Z present-unmatched
bool Rva0016AF80::rva0016AF80(ChunkLoadClass &cload)
{
	ShareBufferClass<Vector3> *vertex = m_vertex40;
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
