// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??_EFileInfoStruct@MixFileCreator@@QAEPAXI@Z, retail 0x002E70E8, 75 bytes.
// Vector deleting destructor for MixFileCreator::FileInfoStruct (element
// size 0x10: buffer + CRC/Offset/Size). The anchor below exists only to make
// this TU emit the destructor through delete[]; it is not a retail function.

void __cdecl operator delete(void *p);
void __cdecl operator delete[](void *p);

class MixFileInfoBuffer
{
public:
	void releaseInto(void *pool);
};

class MixFileCreator
{
public:
	struct FileInfoStruct
	{
		~FileInfoStruct();
		MixFileInfoBuffer *m_buffer;
		unsigned long m_crc;
		unsigned long m_offset;
		unsigned long m_size;
	};
};

// ?_mixFileInfoVecDtorAnchor@@YAXPAUFileInfoStruct@MixFileCreator@@@Z present-unmatched
void _mixFileInfoVecDtorAnchor(MixFileCreator::FileInfoStruct *p)
{
	delete[] p;
}
