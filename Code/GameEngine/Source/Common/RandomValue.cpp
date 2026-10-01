// cl: /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib
// stlport
// Ported verbatim from the Generals Zero Hour reference
// (GameEngine/Source/Common/RandomValue.cpp); this unit had no counterpart under Code/.
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

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// RandomValue.cpp
// Pseudo-random number generators 
// Author: Michael S. Booth, January 1998

#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine


#include "Lib/BaseType.h"
#include "Common/RandomValue.h"
#include "Common/CRC.h"
#include "Common/Debug.h"
#include "GameLogic/GameLogic.h"

//#define DETERMINISTIC				// to allow repetition for debugging

#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif

#undef DEBUG_RANDOM_CLIENT
#undef DEBUG_RANDOM_LOGIC
#undef DEBUG_RANDOM_AUDIO

//#define DEBUG_RANDOM_CLIENT
//#define DEBUG_RANDOM_LOGIC
//#define DEBUG_RANDOM_AUDIO

static const Real theMultFactor = 1.0f / (powf(2, 8 * sizeof(UnsignedInt)) - 1.0f);

// Initial seed values.
static UnsignedInt theGameClientSeed[6] =
{
    0xf22d0e56L, 0x883126e9L, 0xc624dd2fL, 0x702c49cL, 0x9e353f7dL, 0x6fdf3b64L
};

static UnsignedInt theGameAudioSeed[6] =
{
    0xf22d0e56L, 0x883126e9L, 0xc624dd2fL, 0x702c49cL, 0x9e353f7dL, 0x6fdf3b64L
};

static UnsignedInt theGameLogicBaseSeed = 0;
static UnsignedInt theGameLogicSeed[6] =
{
    0xf22d0e56L, 0x883126e9L, 0xc624dd2fL, 0x702c49cL, 0x9e353f7dL, 0x6fdf3b64L
};

// Add with carry. SUM is replaced with A + B + C, C is replaced with 1  if there was a carry, 0 if there wasn't. A carry occurred if the sum is  less than one of the inputs. This is addition, so carry can never be  more than one.
#define ADC(SUM, A, B, C)   SUM = (A) + (B) + (C); C = ((SUM < (A)) || (SUM < (B)))

static UnsignedInt randomValue(UnsignedInt *seed)
{
	UnsignedInt ax;
	UnsignedInt c = 0;
	
	
	ADC(ax, seed[5], seed[4], c);   /*  mov     ax,seed+20  */
	/*  add     ax,seed+16  */
	seed[4] = ax;                   /*  mov     seed+8,ax   */
	
	ADC(ax, ax, seed[3], c);        /*  adc     ax,seed+12  */
	seed[3] = ax;                   /*  mov     seed+12,ax  */
	
	ADC(ax, ax, seed[2], c);        /*  adc     ax,seed+8   */
	seed[2] = ax;                   /*  mov     seed+8,ax   */
	
	ADC(ax, ax, seed[1], c);        /*  adc     ax,seed+4   */
	seed[1] = ax;                   /*  mov     seed+4,ax   */
	
	ADC(ax, ax, seed[0], c);        /*  adc     ax,seed+0   */
	seed[0] = ax;                   /*  mov     seed+0,ax   */
	
	/* Increment seed array, bubbling up the carries. */
	if (!++seed[5])
	{
		if (!++seed[4])
		{
			if (!++seed[3])
			{
				if (!++seed[2])
				{
					if (!++seed[1])
					{
						++seed[0];
						++ax;
					}
				}
			}
		}
	}
	return(ax);
}

static void seedRandom(UnsignedInt SEED, UnsignedInt *seed)
{
	UnsignedInt ax;

	ax = SEED;                      /* mov     eax,SEED                     */
	ax += 0xf22d0e56;               /* add     eax,0f22d0e56h               */
	seed[0] = ax;                   /* mov     seed,eax                     */
	ax += 0x883126e9 - 0xf22d0e56;  /* add     eax,0883126e9h-0f22d0e56h    */
	seed[1] = ax;                   /* mov     seed+4,eax                   */
	ax += 0xc624dd2f - 0x883126e9;  /* add     eax,0c624dd2fh-0883126e9h    */
	seed[2] = ax;                   /* mov     seed+8,eax                   */
	ax += 0x0702c49c - 0xc624dd2f;  /* add     eax,00702c49ch-0c624dd2fh    */
	seed[3] = ax;                   /* mov     seed+12,eax                  */
	ax += 0x9e353f7d - 0x0702c49c;  /* add     eax,09e353f7dh-00702c49ch    */
	seed[4] = ax;                   /* mov     seed+16,eax                  */
	ax += 0x6fdf3b64 - 0x9e353f7d;  /* add     eax,06fdf3b64h-09e353f7dh    */
	seed[5] = ax;                   /* mov     seed+20,eax                  */
}

//
// It is necessary to separate the GameClient and GameLogic usage of random
// values to ensure that the GameLogic remains deterministic, regardless
// of the effects displayed on the GameClient.
//

// GetGameLogicRandomSeed: defined in GameLogicRandomSeed_get.cpp (its row's unit).
UnsignedInt GetGameLogicRandomSeed( void );

// GetGameLogicRandomSeedCRC: defined in GameLogicRandomSeedCRC_get.cpp (its row's unit).
UnsignedInt GetGameLogicRandomSeedCRC( void );

void InitRandom( void )
{
#ifdef DETERMINISTIC
	// needs to be the same every time
	seedRandom(0, theGameClientSeed);
	seedRandom(0, theGameAudioSeed);
	seedRandom(0, theGameLogicSeed);
	theGameLogicBaseSeed = 0;
#else
	time_t seconds = time( NULL );

	seedRandom(seconds, theGameAudioSeed);
	seedRandom(seconds, theGameClientSeed);
	seedRandom(seconds, theGameLogicSeed);
	theGameLogicBaseSeed = seconds;
#endif
}

void InitRandom( UnsignedInt seed )
{
	seedRandom(seed, theGameAudioSeed);
	seedRandom(seed, theGameClientSeed);
	seedRandom(seed, theGameLogicSeed);
	theGameLogicBaseSeed = seed;
#ifdef DEBUG_RANDOM_LOGIC
DEBUG_LOG(( "InitRandom %08lx\n",seed));
#endif
}

// InitGameLogicRandom: defined in GameLogicRandomInit.cpp (its row's unit).
void InitGameLogicRandom( UnsignedInt seed );

//
// Integer random value
//
// GetGameLogicRandomValue: defined in GameLogicRandomValue_getValueInt.cpp (its row's unit).
Int GetGameLogicRandomValue( int lo, int hi, char *file, int line );

//
// Integer random value
//
// GetGameClientRandomValue: defined in GameClientAudioRandomValue_getValueInt.cpp (its row's unit).
Int GetGameClientRandomValue( int lo, int hi, char *file, int line );

//
// Integer random value
//
// GetGameAudioRandomValue: defined in GameClientAudioRandomValue_getValueInt.cpp (its row's unit).
Int GetGameAudioRandomValue( int lo, int hi, char *file, int line );

//
// Real valued random value
//
// GetGameLogicRandomValueReal: defined in GameLogicRandomValue_getValueReal.cpp (its row's unit).
Real GetGameLogicRandomValueReal( Real lo, Real hi, char *file, int line );

//
// Real valued random value
//
// GetGameClientRandomValueReal: defined in ClientRandomValue_getValueReal.cpp (its row's unit).
Real GetGameClientRandomValueReal( Real lo, Real hi, char *file, int line );

//
// Real valued random value
//
// GetGameAudioRandomValueReal: defined in GameAudioRandomValue_getValueReal.cpp (its row's unit).
Real GetGameAudioRandomValueReal( Real lo, Real hi, char *file, int line );

//--------------------------------------------------------------------------------------------------------------
// GameClientRandomVariable
//

/*static*/ const char *GameClientRandomVariable::DistributionTypeNames[] = 
{
	"CONSTANT", "UNIFORM", "GAUSSIAN", "TRIANGULAR", "LOW_BIAS", "HIGH_BIAS"
};

/**
	define the range of random values, and the distribution of values
*/
// GameClientRandomVariable::setRange: defined in ClientRandomValue.cpp (its row's unit).

/**
 * Return a value from the random distribution
 */
// GameClientRandomVariable::getValue: defined in ClientRandomValue_getValue.cpp (its row's unit).


//--------------------------------------------------------------------------------------------------------------
// GameLogicRandomVariable
//

/*static*/ const char *GameLogicRandomVariable::DistributionTypeNames[] = 
{
	"CONSTANT", "UNIFORM", "GAUSSIAN", "TRIANGULAR", "LOW_BIAS", "HIGH_BIAS"
};

/**
	define the range of random values, and the distribution of values
*/
// ?GameLogicRandomVariable::setRange present-unmatched
void GameLogicRandomVariable::setRange( Real low, Real high, DistributionType type )
{
	DEBUG_ASSERTCRASH(!(m_type == CONSTANT && m_low != m_high), ("CONSTANT GameLogicRandomVariables should have low == high"));
	m_low = low;
	m_high = high;
	m_type = type;
}

/**
 * Return a value from the random distribution
 */
// GameLogicRandomVariable::getValue: defined in GameLogicRandomValue_getValue.cpp (its row's unit).


