// cl: /MD /Oi /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/profile
// Native GTT vtable 0xCE85D8 identifies WriteResults at 6C8120, which calls
// this recursive 736B body at 6C7DD0. Ghidra independently records its start
// and extent; ECX carries the writer and RET 24 agrees with thread, FILE,
// root index, 64-bit maximum and frame arguments at the verified call site.
// Its original private method name is unknown: rva006C7DD0WriteGraph is a
// descriptive address-derived name. Donor profiler handles and the recovered
// DOT writer guide semantic labels; native calls, strings, 64-bit arithmetic,
// threshold comparison and visited-edge checks establish this graph traversal.
// GetTime/GetCalls labels retain donor provenance because retail folds their
// disabled-profile implementations. Separate time/call temporaries and the
// explicit percent<100 display branch reproduce the native compiler shape.
#include "profile.h"
#include "profile_funclevel.h"
#include <stdio.h>
#include <string.h>
class ProfileResultFileGTT : public ProfileResultInterface
{
public:
	static ProfileResultInterface *Create(int argn, const char *const *argv);
	ProfileResultFileGTT(const char *fileName, const char *frameName, int percentThreshold);

	virtual void WriteResults();
	virtual void Delete();

	bool MarkVisited(unsigned from, unsigned to);

private:
    void rva006C7DD0WriteGraph(ProfileFuncLevel::Thread &, FILE *, unsigned, unsigned __int64, unsigned);
	struct Edge
	{
		unsigned from;
		unsigned to;
	};

	char *m_fileName;
	char *m_frameName;
	int m_percentThreshold;
	Edge *m_visited;
	unsigned m_numVisited;
	unsigned m_visitedAlloc;
};

void ProfileResultFileGTT::rva006C7DD0WriteGraph(ProfileFuncLevel::Thread &thread, FILE *f,
    unsigned rootIndex, unsigned __int64 maxTime, unsigned frame)
{
    if (maxTime<10000) return;
    ProfileFuncLevel::Id root;
    thread.EnumProfile(rootIndex,root);
    unsigned rootAddress=root.GetAddress();
    ProfileFuncLevel::Id id;
    for (unsigned k=0;thread.EnumProfile(k,id);k++)
    {
        ProfileFuncLevel::IdList callers=id.GetCaller(frame);
        ProfileFuncLevel::Id caller;
        unsigned count;
        for (unsigned i=0;callers.Enum(i,caller,&count);i++)
            if (caller.GetAddress()==rootAddress)
            {
                unsigned __int64 time=id.GetTime(frame);
                unsigned __int64 calls=id.GetCalls(frame);
                unsigned __int64 edgeTime=count*time/calls;
                unsigned percent=(unsigned)(edgeTime/(maxTime/10000));
                if (percent<m_percentThreshold || MarkVisited(rootIndex,k)) continue;
                fprintf(f,"f%08x [label=\"%s\\n%I64iM, %I64i calls\"];\n",root.GetAddress(),root.GetFunction(),
                    (root.GetTime(frame)+500000)/1000000,root.GetCalls(frame));
                fprintf(f,"f%08x [label=\"%s\\n%I64iM, %I64i calls\"];\n",id.GetAddress(),id.GetFunction(),
                    (id.GetTime(frame)+500000)/1000000,id.GetCalls(frame));
                fprintf(f,"f%08x ",root.GetAddress());
                fprintf(f,"-> f%08x",id.GetAddress());
                fprintf(f,"[headlabel=\"\\n%I64iM\\n%i.%02i%%\"];\n",(edgeTime+500000)/1000000,
                    percent<100?0:percent/100,percent%100);
                rva006C7DD0WriteGraph(thread,f,k,maxTime,frame);
            }
    }
}
