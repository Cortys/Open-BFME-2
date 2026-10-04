// cl: -DNDEBUG -DWIN32 -MD -EHsc -Ireference/open-bfme-1/inputs/reference/shims/sweep -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Os -Ireference/open-bfme-1/game/GameEngineDevice/Source/W3DDevice/Common/System
// stlport

// TerrainRoadType::getRadarColor is an inline in GameClient/TerrainRoads.h:
//     inline RGBColor getRadarColor( void ) { return m_radarColor; }
// which the BFME1 donor W3DRadar.cpp only odr-uses. Real definitions of the
// class and RGBColor are modelled locally so the body can be emitted
// out-of-line; retail 0x0004D636 copies this+0x28 to the hidden return buffer,
// proving m_radarColor's offset.
typedef float Real;

struct RGBColor
{
	Real red, green, blue;
};

class TerrainRoadType
{
public:
	RGBColor getRadarColor( void );

private:
	char m_pad[0x28];
	RGBColor m_radarColor;		// this+0x28
};

RGBColor TerrainRoadType::getRadarColor( void )
{
	return m_radarColor;
}
