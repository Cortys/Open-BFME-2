// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// STLport 4.5.3 vector<T>::~vector for element types whose _Destroy range
// helper is already rowed. Every member is the same-shape sibling of the
// AsciiString instantiation at 0x2CC70 (StlportAsciiStringVectorDtor.cpp):
// only the _Destroy callee differs, so each element type needs just a
// non-trivial destructor here to select that callee by name. Sizes and
// members are irrelevant to these bodies and are not modelled.
#include <vector>

// ??1?$vector@UOpaqueRefElement4@@V?$allocator@UOpaqueRefElement4@@@_STL@@@_STL@@QAE@XZ @0x57994 (_Destroy at 0x54f94)
struct OpaqueRefElement4 { public: ~OpaqueRefElement4(); };
template _STL::vector<OpaqueRefElement4>::~vector();

// ??1?$vector@UQuantityModifier@@V?$allocator@UQuantityModifier@@@_STL@@@_STL@@QAE@XZ @0x49e274
// (_Destroy at 0x32c0ca, pinned twin of the rowed 8-byte-pair destroy).
// QuantityModifier is ProductionUpdateModuleData's +0x1C modifier element: an
// 8-byte AsciiString-plus-int pair (full layout in the ctor TU
// ProductionUpdateModuleDataCtor.cpp, INI table 0x00C517F0). The 8-byte
// stride is all this body observes, so the element stays size-free here per
// the family rule; the range destroy folds with Rva0032C0CADestroyPairs.
struct QuantityModifier { public: ~QuantityModifier(); };
template _STL::vector<QuantityModifier>::~vector();

// ??1?$vector@UBfmeVectorRecord000BDF17@@V?$allocator@UBfmeVectorRecord000BDF17@@@_STL@@@_STL@@QAE@XZ @0xc6878 (_Destroy at 0xc37cd)
struct BfmeVectorRecord000BDF17 { public: ~BfmeVectorRecord000BDF17(); };
template _STL::vector<BfmeVectorRecord000BDF17>::~vector();

// ??1?$vector@UBfmeAssignRecord172@@V?$allocator@UBfmeAssignRecord172@@@_STL@@@_STL@@QAE@XZ @0x1eb945 (_Destroy at 0x1eb1b3)
struct BfmeAssignRecord172 { public: ~BfmeAssignRecord172(); };
template _STL::vector<BfmeAssignRecord172>::~vector();

// ??1?$vector@UBfmeObject476@@V?$allocator@UBfmeObject476@@@_STL@@@_STL@@QAE@XZ @0x1fd882 (_Destroy at 0x1fd6a4)
struct BfmeObject476 { public: ~BfmeObject476(); };
template _STL::vector<BfmeObject476>::~vector();

// ??1?$vector@UBfmeAssignRecord104@@V?$allocator@UBfmeAssignRecord104@@@_STL@@@_STL@@QAE@XZ @0x3b904b (_Destroy at 0x3b8e13)
struct BfmeAssignRecord104 { public: ~BfmeAssignRecord104(); };
template _STL::vector<BfmeAssignRecord104>::~vector();

// ??1?$vector@UBfmeAssignRecord44@@V?$allocator@UBfmeAssignRecord44@@@_STL@@@_STL@@QAE@XZ @0x4146e2 (_Destroy at 0x4144f0)
struct BfmeAssignRecord44 { public: ~BfmeAssignRecord44(); };
template _STL::vector<BfmeAssignRecord44>::~vector();

// ??1?$vector@UBfmeObject544@@V?$allocator@UBfmeObject544@@@_STL@@@_STL@@QAE@XZ @0x4cae89 (_Destroy at 0x4cae71)
struct BfmeObject544 { public: ~BfmeObject544(); };
template _STL::vector<BfmeObject544>::~vector();

// ??1?$vector@URvaPair004C3D4C@@V?$allocator@URvaPair004C3D4C@@@_STL@@@_STL@@QAE@XZ @0x4c3d4c (_Destroy at 0x32c0ca, stride-identical fold with rowed Rva0032C0CADestroyPairs).
// ElvenWoodSpecialPowerModuleData's +0x7C member: retail destroys the range through the rowed 8-byte AsciiString-keyed DestroyPairs at 0x32C0CA then frees storage via 0x30830 (EH states 0/-1); called by the ElvenWood dtor at 0x004C3EEC plus its Unwind funclet. The 8-byte stride plus key dtor are all this body observes; true element name unproven so the honest RvaPair address name stands in for the 8-byte AsciiString-plus-int layout the retail destroy proves.
class AsciiString { public: ~AsciiString(); private: char *m_data; };
struct RvaPair004C3D4C { AsciiString m_key; int m_value; public: ~RvaPair004C3D4C(); };
template _STL::vector<RvaPair004C3D4C>::~vector();

// ??1?$vector@URvaPair00257544@@V?$allocator@URvaPair00257544@@@_STL@@@_STL@@QAE@XZ @0x00257544 63B.
// StructureCollapseUpdateModuleData +0xA0 member vector: retail destroys the range through the rowed 8-byte AsciiString-keyed DestroyPairs at 0x32C0CA then frees storage via 0x30830 (EH states 0/-1); called by the StructureCollapse dtor at 0x00257B7A plus Unwind funclets at 0xB720EF/0xB7213E. ICF-twin of rowed 0x004C3D4C and 0x0049E274 (same 63B Destroy+free shape). True element name unproven so honest RvaPair address name stands in for the 8-byte AsciiString-plus-int layout the retail destroy proves.
struct RvaPair00257544 { AsciiString m_key; int m_value; public: ~RvaPair00257544(); };
template _STL::vector<RvaPair00257544>::~vector();

