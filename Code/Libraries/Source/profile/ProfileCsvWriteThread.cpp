/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// cl: /MD /Oi /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/profile
#include "profile.h"
#include "profile_funclevel.h"
#include <stdio.h>
#include <string.h>
#include "profile_result.h"
class ProfileResultFileCSV : public ProfileResultInterface
{
    void WriteThread(ProfileFuncLevel::Thread &thread);
public:
    virtual void WriteResults();
    virtual void Delete();
    virtual const char *GetName() const;
private:
    char *m_fileName;
};
// The donor supplies the CSV writer and handle classes. Retail's string
// references identify comma-separated output, and its caller enumeration adds
// a 50-caller cap with a threshold and a misc total. The recovered constructor
// establishes the optional filename at +4. Handle names/types follow the donor;
// each native call's cleanup and folded return value independently agree.
// This 300-byte named buffer covers retail's strncpy request and terminator;
// its initial target span is zero, but the original allocation extent is unknown.
char profile_csv_source[300];
// The private helper also survives out of line at native 6C6E80, between
// independent int3 runs. MSVC emits its private source-argument ABI in EAX.
// Full byte verification checks that ABI; its original name is unknown.
static __forceinline const char *rva006C6E80CsvName(const char *name)
{
    strncpy(profile_csv_source, name, sizeof(profile_csv_source));
    profile_csv_source[sizeof(profile_csv_source)-1] = 0;
    for (char *p = profile_csv_source; *p; ++p)
        if (*p == ',') *p = ';';
    return profile_csv_source;
}
void ProfileResultFileCSV::WriteThread(ProfileFuncLevel::Thread &thread)
{
    char help[40];
    sprintf(help,"prof%08x-all.csv",thread.GetId());
    FILE *f=fopen(m_fileName ? m_fileName : help,"wt");
    fprintf(f,"Function,File,Call count,PTT (all),GTT (all),PT/C (all),GT/C (all),Caller (all)");
    for (unsigned k=0;k<Profile::GetFrameCount();k++)
    {
        const char *s=Profile::GetFrameName(k);
        fprintf(f,",Call (%s),PTT (%s),GTT (%s),PT/C (%s),GT/C (%s),Caller (%s)",s,s,s,s,s,s);
    }
    fprintf(f,"\n");
    ProfileFuncLevel::Id id;
    for (k=0;thread.EnumProfile(k,id);k++)
    {
        const char *function = rva006C6E80CsvName(id.GetFunction());
        fprintf(f,"%s[%08x],%s#%i",function,id.GetAddress(),id.GetSource(),id.GetLine());
        for (unsigned i=ProfileFuncLevel::Id::Total;i!=Profile::GetFrameCount();i++)
        {
            if (!id.GetCalls(i))
            {
                fprintf(f,",,,,,,");
                continue;
            }
            fprintf(f,",%I64i",id.GetCalls(i));
            fprintf(f,",%I64i",id.GetFunctionTime(i));
            fprintf(f,",%I64i",id.GetTime(i));
            fprintf(f,",%I64i",id.GetFunctionTime(i)/id.GetCalls(i));
            fprintf(f,",%I64i",id.GetTime(i)/id.GetCalls(i));
            ProfileFuncLevel::IdList idlist=id.GetCaller(i);
            fprintf(f,",");
            ProfileFuncLevel::Id callid;
            unsigned j;
            if (idlist.Enum(50,callid))
            {
                unsigned threshold=1;
                unsigned number;
                do
                {
                    number=0;
                    unsigned next=~0U;
                    unsigned count;
                    for (j=0;idlist.Enum(j,callid,&count);j++)
                        if (count > threshold)
                        {
                            number++;
                            if (count < next) next=count;
                        }
                    if (number > 50) threshold=next;
                } while (number > 50);
                unsigned misc=0;
                unsigned count;
                for (j=0;idlist.Enum(j,callid,&count);j++)
                    if (count > threshold)
                    {
                        const char *function=rva006C6E80CsvName(callid.GetFunction());
                        fprintf(f," %s[%08x](%i)",function,callid.GetAddress(),count);
                    }
                    else misc+=count;
                if (misc > 0) fprintf(f," misc(%i)",misc);
            }
            else
            {
                unsigned count;
                for (j=0;idlist.Enum(j,callid,&count);j++)
                {
                    const char *function=rva006C6E80CsvName(callid.GetFunction());
                    fprintf(f," %s[%08x](%i)",function,callid.GetAddress(),count);
                }
            }
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
