// ?updateLighting@W3DRoadBuffer@@QAEXXZ
// partial score=0.95 date=2026-10-01
// Banked attempt: W3DRoadBuffer::updateLighting, 49 B @0x000D4A4B.
// Status when banked: the body is BYTE-EXACT and verified (./build.sh with the
// TU's object cache invalidated: Functions OK 71/71, string-ref/float-ref/
// import-ref OK); it is not landed because its last delta needs a header edit
// and this workspace's full gate -- which every .h edit forces -- crashes
// before it can pass. See "WHY NOT LANDED" at the bottom.
//
// Boundary, read from the retail image on both sides: the already-matched
// setMap body 0x000D4A24+39 B ends at this address (its tail is
// 89 7e 10 5f 5e c2 04 00) and the next body starts at 0x000D4A7C, so the 49
// bytes in between are this body:
//   53 56 8b f1 33 db 38 5e 0c 74 23 57 33 ff 39 5e 08 7e 16 8b 4e 04
//   03 cb e8 ab fb ff ff 47 81 c3 bc 00 00 00 3b 7e 08 7c ea c6 46 4c 01
//   5f 5e 5b c3
//
// Landing = two edits, both measured target-side:
//
// (1) reference/shims/w3droadbuffer/W3DDevice/GameClient/W3DRoadBuffer.h, the
//     LOAD_TEST_ASSETS slot at this+0x4C. Retail closes with c6 46 4c 01 =
//     mov byte [esi+0x4C],1, so that slot is ONE byte wide and the donor's Int
//     (m_curOpenRoad, donor semantics, unverified) cannot emit it. m_updateBuffers
//     stays at +0x50 (the matched updateCenter body 0x00050CF7 is
//     c6 41 50 01 c3 = mov byte [ecx+0x50],1), so the 4-byte slot is shared:
//
//         #ifdef LOAD_TEST_ASSETS
//         union {
//             Int m_curOpenRoad;
//             unsigned char m_retailByte4C;
//         };
//         #endif
//
// (2) the body itself in
//     Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DRoadBuffer.cpp,
//     differing from the ZH donor body in exactly the guard member and the store
//     member (both verified byte-exact once edited):

// void W3DRoadBuffer::updateLighting(void)
// {
//     if ( !m_initialized )          // retail: cmp byte [esi+0xc],bl / je -- the
//     {                              // same guard the matched siblings
//         return;                    // moveRoadSegTo and addMapObject carry.
//     }
//     Int curRoad;
//     for (curRoad=0; curRoad<m_numRoads; curRoad++) {
//         m_roads[curRoad].updateSegLighting();
//     }
//     m_retailByte4C = 1;            // retail: c6 46 4c 01
// }

// Callee pin the body needs (not added to symbols.csv: it belongs to the
// landing, and a pin whose note cites an unlanded body confuses the ledger):
//   ?updateSegLighting@RoadSegment@@QAEXXZ,0x000D4613 -- read from the REL32 at
//   the body's +0x18 (call site 0x000D4A63 = e8 ab fb ff ff). pin_consistency
//   --symbol reports it consistent, but the ZH-derived body this TU defines
//   under that name does NOT reproduce the retail body at 0x000D4613, so the pin
//   is a call address only and the address stays unrowed.
//
// WHY NOT LANDED: a header edit forces pre-commit's FULL gate. In this tree the
// full gate is red for reasons that are not this body's:
//   * ./build.sh (no args) crashes in verify_functions on the stale gen-funclet
//     row uw_0076443a (functions.csv, source
//     Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DDisplayString.cpp):
//     object-symbol=$L45548 does not exist in the object freshly compiled from
//     that TU, so read_object_symbol_bytes raises "symbol not found in object"
//     and the gate dies before reporting its FAIL list. Reproduced after
//     deleting that TU's obj+deps sidecar, so it is not cache reuse.
//   * a second full-gate run had reported FAIL for
//     ?Make_UV_Array_Unique@MeshMatDescClass@@QAEXHH@Z
//     (meshmatdesc.cpp, 4-byte stack-displacement delta) and a compile failure
//     for Coord3DVectorFillInsertO1.cpp (coord.h C2011). Both were flaky-wine /
//     poisoned-object artifacts: recompiling each TU after deleting its obj and
//     deps sidecar restores 24/24 and 1/1 matched respectively.
// Landing this body needs the full gate to run at all, which needs the
// gen-funclet row repaired (or the funclet-row verification made to skip a
// missing label) -- repo work outside this card.
