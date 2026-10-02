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
// Zero Hour profile_funclevel.cpp supplies the !HAS_PROFILE empty-data path.
// Native CSV calls establish Id/IdList handles and thiscall cleanup; independent
// retail starts at 6C8780/6C8790/6C87A0 confirm their zero/false/empty results.
// GetTime/GetFunctionTime share GetCalls' native 64-bit zero body. The existing
// 32-bit zero, boolean enumeration and frame-count bodies are reused via ABI
// bindings rather than claimed again. Accessor names retain donor provenance.
#include "profile_funclevel.h"

unsigned __int64 ProfileFuncLevel::Id::GetCalls(unsigned frame) const
{
    return 0;
}

bool ProfileFuncLevel::Thread::EnumProfile(unsigned index, Id &id) const
{
    return false;
}

ProfileFuncLevel::IdList ProfileFuncLevel::Id::GetCaller(unsigned frame) const
{
    return IdList();
}

#pragma comment(linker, "/alternatename:?GetTime@Id@ProfileFuncLevel@@QBE_KI@Z=?GetCalls@Id@ProfileFuncLevel@@QBE_KI@Z")
#pragma comment(linker, "/alternatename:?GetFunctionTime@Id@ProfileFuncLevel@@QBE_KI@Z=?GetCalls@Id@ProfileFuncLevel@@QBE_KI@Z")
#pragma comment(linker, "/alternatename:?Enum@IdList@ProfileFuncLevel@@QBE_NIAAVId@2@PAI@Z=?rva006C8770@Rva006C8770@@QAE_NHHH@Z")
#pragma comment(linker, "/alternatename:?GetFrameCount@Profile@@SAIXZ=?Rva006C53B0Get@@YAHXZ")
#pragma comment(linker, "/alternatename:?GetFunction@Id@ProfileFuncLevel@@QBEPBDXZ=?sync@?$basic_streambuf@GV?$char_traits@G@_STL@@@_STL@@MAEHXZ")
#pragma comment(linker, "/alternatename:?GetSource@Id@ProfileFuncLevel@@QBEPBDXZ=?sync@?$basic_streambuf@GV?$char_traits@G@_STL@@@_STL@@MAEHXZ")
#pragma comment(linker, "/alternatename:?GetAddress@Id@ProfileFuncLevel@@QBEIXZ=?sync@?$basic_streambuf@GV?$char_traits@G@_STL@@@_STL@@MAEHXZ")
#pragma comment(linker, "/alternatename:?GetLine@Id@ProfileFuncLevel@@QBEIXZ=?sync@?$basic_streambuf@GV?$char_traits@G@_STL@@@_STL@@MAEHXZ")
