// cl: /O1
//
// FrameData's two accessors that FrameDataManager calls: getCommandCount,
// retail 0x005801F2 (+0x04), and getCommandList, retail 0x0030F45F
// (+0x08). Retail folded each with an identical one-load getter.

typedef unsigned int UnsignedInt;
class NetCommandList;

class FrameData
{
public:
	UnsignedInt getCommandCount(void);
	NetCommandList *getCommandList(void);

private:
	UnsignedInt m_frame;			// +0x00
	UnsignedInt m_commandCount;		// +0x04
	NetCommandList *m_commandList;	// +0x08
};

UnsignedInt FrameData::getCommandCount(void)
{
	return m_commandCount;
}

NetCommandList *FrameData::getCommandList(void)
{
	return m_commandList;
}
