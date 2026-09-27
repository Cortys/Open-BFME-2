// ??0FrameDataManager@@QAE@_N@Z
// partial score=0.96 date=2026-09-27
// ??0FrameDataManager@@QAE@_N@Z
// partial score=0.96 date=2026-09-27
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /G7 /EHsc
typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;
#define FRAME_DATA_LENGTH (*(const int *)0x00DD2DB8)
class FrameData {
public:
    FrameData();
    ~FrameData();
private:
    unsigned int m_frameCommandCount;
    unsigned int m_commandCount;
    void *m_commandList;
    char storage[8];
};
class FrameDataManager {
public:
    FrameDataManager(Bool isLocal);
    virtual ~FrameDataManager();
private:
    FrameData *m_frameData;
    bool m_isLocal;
    bool m_isQuitting;
    unsigned int m_quitFrame;
};
FrameDataManager::FrameDataManager(Bool isLocal) {
    m_isLocal = isLocal;
    m_frameData = new FrameData[FRAME_DATA_LENGTH];
    m_isQuitting = false;
    m_quitFrame = 0;
}
