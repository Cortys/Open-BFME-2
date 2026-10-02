// cl: /DNDEBUG /MD /EHa /Oy-

#include <new>

extern void *DebugAllocMemory(unsigned size);

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/debug_io.h
class Debug;
class DebugIOInterface
{
protected:
    virtual ~DebugIOInterface(void) {}

public:
    DebugIOInterface(void) {}
    enum StringType { Assert = 0, Check, Log, Crash, Exception, CmdReply, StructuredCmdReply, Other, MAX };
    virtual int Read(char *buf, int maxchar) = 0;
    virtual void Write(StringType type, const char *src, const char *str) = 0;
    virtual void EmergencyFlush(void) = 0;
    virtual void Execute(class Debug &dbg, const char *cmd, bool structuredCmd, unsigned argn, const char *const *argv) = 0;
    virtual void Delete(void) = 0;
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/internal_io.h
class DebugIOOds : public DebugIOInterface
{
public:
    explicit DebugIOOds(void) {}
    virtual int Read(char *buf, int maxchar) { return 0; }
    virtual void Write(StringType type, const char *src, const char *str);
    virtual void EmergencyFlush(void) {}
    virtual void Execute(class Debug &dbg, const char *cmd, bool structuredCmd, unsigned argn, const char *const *argv) {}
    static DebugIOInterface *Create(void);
    virtual void Delete(void);
};

// ?Create@DebugIOOds@@SAPAVDebugIOInterface@@XZ
DebugIOInterface *DebugIOOds::Create(void)
{
    return new (DebugAllocMemory(sizeof(DebugIOOds))) DebugIOOds();
}
