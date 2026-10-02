// ?rva00212A16@Rva000427195@@QAEPAXPBX@Z
// partial score=0.88 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva00212A16@Rva000427195@@QAEPAXPBX@Z, retail 0x00212A16, 68 bytes.
// Hashtable insert for the AsciiString-keyed 12-byte node family shared
// with 0x00212A5A and new_node 0x00212354 and resize 0x00212858. Resizes
// to count+1 via pinned 0x00212858 then buckets via rowed 0x00223149
// then allocates via member twin of rowed 0x00212354 and links it.
// Returns node+4 pair. Caller 0x002138B3 in 0x0021386C. Flags from prev plus ascii.
#include "ascii_string.h"

class Rva000427195
{
public:
    void rva00212858(unsigned int newSize);
    int bucketIndex(const AsciiString *name);
    void *rva00212354(const void *src);
    void *rva00212A16(const void *key);

    void *m_unused00;
    void **m_beginBuckets;
    void **m_endBuckets;
    void **m_storageEnd;
    unsigned int m_numElements;
};

// ?rva00212A16@Rva000427195@@QAEPAXPBX@Z present-unmatched
void *Rva000427195::rva00212A16(const void *key)
{
    const AsciiString *skey = (const AsciiString *)key;
    rva00212858(m_numElements + 1);
    int bucket = bucketIndex(skey);
    void *node = rva00212354(skey);
    *(void **)node = m_beginBuckets[bucket];
    m_beginBuckets[bucket] = node;
    ++m_numElements;
    return (char *)node + 4;
}
