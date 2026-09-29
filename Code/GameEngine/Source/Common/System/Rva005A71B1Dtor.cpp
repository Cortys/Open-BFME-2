// cl: /O1 /EHs /MD

// ??1Rva005A71B1@@UAE@XZ @0x005A71B1 79B: dtor stores vtable 0x00871BF8,
// destroys 0x40-element array at +0x218 via ehvec dtor, frees ptr at +4 via
// _free 0x00030830. Element dtor pointer is 0x005A66B8. Unblocks ??_G at
// 0x005A7200 and 0x005A734B.

extern "C" void __cdecl free(void *block);

class Rva005A66B8Elem
{
public:
    virtual ~Rva005A66B8Elem() {}
private:
    int m_pad[4];
};

class Rva005A71B1Base
{
public:
    ~Rva005A71B1Base() { if (m_ptr) free(m_ptr); }
protected:
    char *m_ptr;
};

class Rva005A71B1 : public Rva005A71B1Base
{
public:
    virtual ~Rva005A71B1();
private:
    unsigned char m_pad[0x210];
    Rva005A66B8Elem m_arr[0x40];
};

Rva005A71B1::~Rva005A71B1()
{
}
