// cl: /O1 /MD /DNDEBUG /arch:SSE2
// Reference: GameLOD.cpp / GameLODManagerConstructor.cpp at BFME 1 revision
// 10af19f44a89ab7ecc23195bb9a842ceafbc02c9 guide the LOD default-initialization
// purpose. Retail manager constructor 0x00201EAC (Ghidra extent 353B) passes
// VA0x00601DC4 to the array-construction helper 0x00001423 with count6 and
// stride0x4C. Independent instruction decoding gives [0x00201DC4..0x00201E2B).
// Each scalar/flag offset and value below comes from that target body. Address
// labels retain uncertainty about the original component and member names;
// donor class layouts are not asserted as native types.
struct Rva00201DC4LODInfo
{
    Rva00201DC4LODInfo();
    int word00, word04, word08;
    bool flag0C, flag0D, flag0E;
    int word10;
    bool flag14, flag15;
    int word18;
    bool flag1C;
    int word20, word24, word28, word2C;
    bool flag30;
    int word34, word38;
    bool flag3C, flag3D;
    int word40, word44, word48;
};

Rva00201DC4LODInfo::Rva00201DC4LODInfo()
{
    word00=2; word04=3; word08=2500;
    flag0C=true; flag0D=true; flag0E=false;
    word10=3; flag14=true; flag15=true; word18=2;
    flag1C=true; word20=100; word24=25; word28=300000;
    word2C=0; flag30=true; word34=3; word38=0;
    flag3C=false; flag3D=false; word40=2; word44=1; word48=1;
}
