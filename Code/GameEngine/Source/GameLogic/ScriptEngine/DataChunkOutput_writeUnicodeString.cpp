// cl: /O1 /G7
//
// DataChunkOutput::writeUnicodeString, retail 0x0030708E, 99 bytes.
//
// Ported from the Zero Hour reference
// (GameEngine/Source/Common/System/DataChunk.cpp, writeUnicodeString)
// and the BFME1 donor DataChunk.cpp.
// Retail writes a U16 length then len*2 wide bytes, destroying the by-value
// UnicodeString temp via the pinned wide releaseBuffer at 0x00036E70.
// Evidence: caller at 0x00307E46 in writeDict passes the Dict Unicode temp;
// empty wide path corresponds to retail VA 0x00BBB5C4.

typedef unsigned short UnsignedShort;
typedef unsigned short WideChar;

extern "C" __declspec(dllimport) unsigned int __cdecl fwrite(
	const void *chunkBuffer, unsigned int elementSize, unsigned int elementCount, void *outputFile) throw();

template <typename T>
class StringBase
{
	friend class UnicodeString;

private:
	void releaseBuffer() throw();

	struct Header
	{
		int headerRefCount;
		UnsignedShort headerLength; ///< retail +0x04
		UnsignedShort headerCapacity;
		T headerData[1]; ///< retail +0x08
	};

	Header *m_data;
};

class UnicodeString
{
public:
	int getLength() const
	{
		return m_data.m_data ? m_data.m_data->headerLength : 0;
	}

	const WideChar *getStringData() const
	{
		return m_data.m_data ? &m_data.m_data->headerData[0] : (const WideChar *)L"";
	}

	~UnicodeString() { m_data.releaseBuffer(); }

private:
	StringBase<WideChar> m_data;
};

class DataChunkOutput
{
public:
	void writeUnicodeString(UnicodeString textValue);

private:
	void *outputStream; ///< retail this+0x00
	void *tempFile; ///< retail this+0x04
};

void DataChunkOutput::writeUnicodeString(UnicodeString textValue)
{
	UnsignedShort textLength = (UnsignedShort)textValue.getLength();
	::fwrite((const char *)&textLength, sizeof(UnsignedShort), 1, tempFile);
	::fwrite(textValue.getStringData(), textLength * sizeof(WideChar), 1, tempFile);
}
