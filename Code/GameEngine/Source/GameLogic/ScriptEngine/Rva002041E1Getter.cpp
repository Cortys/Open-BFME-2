// cl: /O1 /EHsc
//
// ?rva002041E1@Rva002041E1@@QBE?AVAsciiString@@XZ @0x002041E1 27B: AsciiString getter at +0x44.
// Evidence: same copy-through-pin shape as ParticleSystemTemplate getters 0x00002600 and 0x0000261E;
// callee StringBase copy pin 0x000365F0; callers 0x000DE648 and 0x00209E15 and 0x002DB64E take AsciiString by value.

template <typename T>
class StringBase
{
    friend class AsciiString;
    StringBase(const StringBase<T> &that);
    struct Header
    {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
};

class AsciiString
{
public:
    AsciiString(const AsciiString &that)
    {
        ((StringBase<char> *)this)->StringBase<char>::StringBase(
            *(const StringBase<char> *)&that);
    }
    ~AsciiString();
    AsciiString &operator=(const AsciiString &that);
private:
    char *m_text;
};

struct Rva002041E1
{
    char pad[0x44];
    AsciiString m_name;
    AsciiString rva002041E1() const;
};

AsciiString Rva002041E1::rva002041E1() const
{
    return m_name;
}
