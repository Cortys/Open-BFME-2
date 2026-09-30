// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// Typed STLport vector helper.  The element identity is established by the
// worker at 0x000642AF, which copies MixFileCreator::FileInfoStruct through
// the matched copy constructor at 0x00063CBC -> 0x00217624.  The record is
// three dwords followed by an AsciiString, hence the proven 16-byte stride.
#include <vector>

#include "ascii_string.h"


class MixFileCreator
{
public:
    struct FileInfoStruct
    {
        FileInfoStruct();
        FileInfoStruct(const FileInfoStruct &src);
        FileInfoStruct &operator=(const FileInfoStruct &src);
        unsigned long CRC;
        unsigned long Offset;
        unsigned long Size;
        AsciiString Filename;
    };
};

template class _STL::vector<MixFileCreator::FileInfoStruct,
                            _STL::allocator<MixFileCreator::FileInfoStruct> >;
