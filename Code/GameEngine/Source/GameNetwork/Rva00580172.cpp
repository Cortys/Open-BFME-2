// cl: /O1
// ?rva00580172@Rva00580172@@QAE_NXZ @0x00580172 16B.
// Test-and-clear byte at +0x14: if set clear and return true else false.
// Evidence: callers 0x0044650A 0x005A0D92; prev/next share /O1.
class Rva00580172
{
public:
    bool rva00580172();

private:
    char m_pad[0x14];
    unsigned char m_14;
};

bool Rva00580172::rva00580172()
{
    if (m_14 != 0) {
        m_14 = 0;
        return true;
    }
    return false;
}
