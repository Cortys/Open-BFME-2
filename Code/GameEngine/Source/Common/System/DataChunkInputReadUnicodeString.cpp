// cl: /O1 /DNDEBUG /MD /G7
// ?rva003075A3@DataChunkInput@@QAE?AVUnicodeString@@XZ @0x003075A3 158B
// DataChunkInput counted-string reader (readUnicodeString shape): reads u16
// len via virtual read, decrements, getBufferForRead, reads len*2 bytes, null
// terms wide, returns UnicodeString by value via StringBase copy plus release.
// Evidence: unlock lane, sibling readAsciiString 0x0030750A same /O1,
// callees rowed decrement 0x00306E40 release 0x00036E70 copy 0x00037050
// plus pin getBufferForRead 0x000370A0, caller at 0x003078D3.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
typedef bool Bool;

template <typename T>
class StringBase
{
public:
    StringBase(void) : m_data(0) {}
    T *getBufferForRead(Int len);

private:
    StringBase(const StringBase &other);
    void releaseBuffer();
    friend class UnicodeString;

protected:
    void *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
public:
    UnicodeString(void) : StringBase<unsigned short>() {}
    UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    ~UnicodeString() { ((StringBase<unsigned short> *)this)->releaseBuffer(); }

private:
    // keep 4-byte layout via base only
};

class ChunkInputStream
{
public:
    virtual Int read(void *pData, Int numBytes);
    virtual Int tell(void);
    virtual void absoluteSeek(Int pos);
    virtual Bool eof(void);
};

class InputChunk
{
public:
    virtual ~InputChunk();

    InputChunk *next;
    UnsignedInt id;
    UnsignedShort version;
    UnsignedShort padding;
    Int chunkStart;
    Int dataSize;
    Int dataLeft;
};

class DataChunkTableOfContents
{
public:
    void *m_list;
    Int m_listLength;
    UnsignedInt m_nextID;
    Bool m_headerOpened;
};

class DataChunkInput
{
public:
    UnicodeString rva003075A3();

protected:
    void decrementDataLeft(Int size);

private:
    ChunkInputStream *m_file;
    DataChunkTableOfContents m_contents;
    Int m_fileposOfFirstChunk;
    void *m_parserList;
    InputChunk *m_chunkStack;
};

UnicodeString DataChunkInput::rva003075A3(void)
{
    UnsignedShort len;
    m_file->read(&len, sizeof(UnsignedShort));
    decrementDataLeft(sizeof(UnsignedShort));

    UnicodeString theString;
    if (len > 0)
    {
        unsigned short *str = theString.getBufferForRead(len);
        m_file->read(str, len * 2);
        decrementDataLeft(len * 2);
        str[len] = 0;
    }

    return theString;
}
