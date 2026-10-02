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
// Names and public handles follow ZH profile_highlevel.cpp. The independent
// native starts 6C5FB0/6C5FC0/6C5FE0 read the handle's pointee at +4/+8/+C.
// CSV output calls establish the name and unit roles; their record offsets
// also agree with the existing ProfileId constructor and frame recorder.
// Retail description/unit reads add an empty-string result for a null field;
// a null handle still returns NULL. This view covers only the accessed prefix.
#include "profile_highlevel.h"
struct ProfileIdTextView
{
    void *next;
    const char *name;
    const char *description;
    const char *unit;
};

const char *ProfileHighLevel::Id::GetName() const
{
    return m_idPtr ? ((const ProfileIdTextView *)m_idPtr)->name : 0;
}

const char *ProfileHighLevel::Id::GetDescr() const
{
    return m_idPtr ? (((const ProfileIdTextView *)m_idPtr)->description
        ? ((const ProfileIdTextView *)m_idPtr)->description : "") : 0;
}

const char *ProfileHighLevel::Id::GetUnit() const
{
    return m_idPtr ? (((const ProfileIdTextView *)m_idPtr)->unit
        ? ((const ProfileIdTextView *)m_idPtr)->unit : "") : 0;
}
