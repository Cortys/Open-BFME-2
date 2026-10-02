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
// ZH's DOT writer supplies the thread/frame selection structure; BFME2's
// GTT output is new. The recovered GTT constructor installs vtable 0xCE85D8,
// whose first slot points to 6C8120. Ghidra independently records this 575B
// body; RET at 6C835E followed by padding confirms its complete boundary.
// Native calls show a caller-presence scan before opening the output, then
// a maximum-time root selection and the recursive graph helper at 6C7DD0.
// The graph headers, control flow and six pushed helper arguments are target
// evidence. Profiler accessor semantic labels retain donor provenance where
// the disabled-profile implementations are folded to common empty bodies.
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

void ProfileResultFileGTT::WriteResults()
{
  // search "main" thread
  ProfileFuncLevel::Thread t,tMax;
  if (!ProfileFuncLevel::EnumThreads(0,tMax))
    return;

  unsigned curMax=0;
  for (unsigned k=1;ProfileFuncLevel::EnumThreads(k,t);k++)
  {
    for (;curMax++;)
    {
      ProfileFuncLevel::Id help;
      if (!tMax.EnumProfile(curMax,help))
      {
        tMax=t;
        break;
      }
      if (!t.EnumProfile(curMax,help))
        break;
      curMax++;
    }
  }

  // search frame
  unsigned frame=ProfileFuncLevel::Id::Total;
  if (m_frameName)
  {
    for (unsigned k=0;k<Profile::GetFrameCount();k++)
      if (!strcmp(Profile::GetFrameName(k),m_frameName))
      {
        frame=k;
        break;
      }
  }


  ProfileFuncLevel::Id id;
  bool hasCallers=false;
  for (k=0;tMax.EnumProfile(k,id);k++)
  {
    ProfileFuncLevel::Id caller;
    if (id.GetCaller(frame).Enum(0,caller))
    {
      hasCallers=true;
      break;
    }
  }
  if (!hasCallers) return;
  FILE *f=fopen(m_fileName,"wt");
  if (!f) return;
  fprintf(f,"digraph G {\n");
  fprintf(f,"node [shape=box, fontname=Arial]\n");
  fprintf(f,"edge [arrowhead=open, labelfontname=Arial, labelfontsize=10, labelangle=0, labelfontcolor=red]\n");
  unsigned __int64 largest=0;
  unsigned root=0;
  for (k=0;tMax.EnumProfile(k,id);k++)
    if (id.GetTime(frame)>largest)
    {
      largest=id.GetTime(frame);
      root=k;
    }
  rva006C7DD0WriteGraph(tMax,f,root,largest,frame);
  fprintf(f,"}\n");
  fclose(f);
}
