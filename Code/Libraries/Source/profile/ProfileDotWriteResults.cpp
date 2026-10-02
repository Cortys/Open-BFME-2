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
// ZH profile_result.cpp supplies the DOT writer and fold-list structure.
// Retail's DOT constructor installs vtable 0x00CE84D0, whose first slot points
// to 6C6F70. The early exit shares cleanup at 6C7432; the full body ends in
// ret at 6C7437 then int3 padding, so its extent is 1224B (Ghidra counts 1218).
// Target evidence adds signed active-count comparisons, open/closed arrows,
// source-group labels,
// per-group ID caller queries and four spaces in edge counts. The folded path
// still scans caller sources but emits no edge writes; retain that behavior.
// Native alloc size 0x330 and fields +0x328/+0x32C agree with the donor's
// 200-handle group layout. Semantic names remain donor provenance.
#include "profile.h"
#include "profile_funclevel.h"
#include "profile_result.h"
#include <stdio.h>
#include <string.h>
void *ProfileAllocMemory(unsigned int size);
void ProfileFreeMemory(void *memory);
class ProfileResultFileDOT : public ProfileResultInterface
{
public:
    enum { MAX_FUNCTIONS_PER_FILE=200 };
    virtual void WriteResults();
    virtual void Delete();
private:
    struct FoldHelper
    {
        FoldHelper *next;
        const char *source;
        ProfileFuncLevel::Id id[MAX_FUNCTIONS_PER_FILE];
        unsigned numId;
        bool mark;
    };
    char *m_fileName;
    char *m_frameName;
    int m_foldThreshold;
};
void ProfileResultFileDOT::WriteResults(void)
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

  // determine number of active functions
  int active=0;
  ProfileFuncLevel::Id id;
  for (k=0;tMax.EnumProfile(k,id);k++)
    if (id.GetCalls(frame))
      active++;

  FILE *f=fopen(m_fileName,"wt");
  if (!f)
    return;

  // DOT header
  fprintf(f,"digraph G { rankdir=\"LR\";\n");
  fprintf(f,"node [shape=box, fontname=Arial]\n");
  fprintf(f,"edge [arrowhead=%s, labelfontname=Arial, labelfontsize=10, labelangle=0, labelfontcolor=blue]\n",
    active>m_foldThreshold?"closed":"open");

  // fold or not?
  if (active>m_foldThreshold)
  {
    // folding version

    // build source code clusters first
    FoldHelper *fold=NULL;
    for (k=0;tMax.EnumProfile(k,id);k++)
    {
      const char *source=id.GetSource();
      for (FoldHelper *cur=fold;cur;cur=cur->next)
        if (!strcmp(source,cur->source))
        {
          if (cur->numId<MAX_FUNCTIONS_PER_FILE)
            cur->id[cur->numId++]=id;
          break;
        }
      if (!cur)
      {
        cur=(FoldHelper *)ProfileAllocMemory(sizeof(FoldHelper));
        cur->next=fold;
        fold=cur;
        cur->source=source;
        cur->numId=1;
        cur->id[0]=id;
      }
    }

    // now write data
    for (FoldHelper *cur=fold;cur;cur=cur->next)
    {
      FoldHelper *cur2;
      for (cur2=fold;cur2;cur2=cur2->next)
        cur2->mark=false;
      
      fprintf(f,"\"%s\";\n",cur->source);
      for (k=0;k<cur->numId;k++)
      {
        ProfileFuncLevel::IdList idlist=cur->id[k].GetCaller(frame);
        ProfileFuncLevel::Id caller;
        for (unsigned i=0;idlist.Enum(i,caller);i++)
        {
          const char *s=caller.GetSource();
          for (FoldHelper *candidate=fold;candidate;candidate=candidate->next)
            if (!strcmp(candidate->source,s))
              break;
          // Retail retains this source lookup and emits no folded edge.
          // The lookup remains for the native access behavior; no folded edge
          // write survives in this target path.
        }
      }
    }

    // cleanup
    while (fold)
    {
      FoldHelper *next=fold->next;
      ProfileFreeMemory(fold);
      fold=next;
    }
  }
  else
  {
    // non-folding version
    for (k=0;tMax.EnumProfile(k,id);k++)
      if (id.GetCalls(frame))
        fprintf(f,"f%08x [label=\"%s\"]\n",id.GetAddress(),id.GetFunction());
    for (k=0;tMax.EnumProfile(k,id);k++)
    {
      ProfileFuncLevel::IdList idlist=id.GetCaller(frame);
      ProfileFuncLevel::Id caller;
      unsigned count;
      for (unsigned i=0;idlist.Enum(i,caller,&count);i++)
        fprintf(f,"f%08x -> f%08x [headlabel=\"%i    \"];\n",caller.GetAddress(),id.GetAddress(),count);
    }
  }

  fprintf(f,"}\n");
  fclose(f);
}

