// ?updateBuddyStatus@@YAXW4GameSpyBuddyStatus@@HV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@Z
// partial score=0.95 date=2026-10-02
// Banked near-exact body for
// ?updateBuddyStatus@@YAXW4GameSpyBuddyStatus@@HV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@Z
// @ 0x003896E7, 347 bytes, in
// Code/GameEngine/Source/GameNetwork/GameSpy/Thread/PeerThread.cpp
//
// State: compiled body is 341 bytes; the ONLY remaining difference is two
// 3-byte unwind state stores, `or DWORD PTR [ebp-4],0xffffffff`, that retail
// emits immediately before each inlined ~basic_string(gameName) cleanup (early
// return at 0x389705 and the normal return at 0x389825). Every other byte of
// the 341-byte body agrees with the target modulo the resulting 3-byte branch
// displacement shift.
//
// Two file-level levers produced this body and are REQUIRED to reproduce it:
//   1. `// cl: ... /Ireference/shims/bfmealloc ...` on PeerThread.cpp. The
//      stock allocator's deallocate calls operator delete 0x0002FD60; retail
//      calls the plain C free 0x00030830. The bfmealloc shim's allocator<char>
//      deallocate calls ::free, which reproduces the direct free call. All 30
//      already-matched rows in the TU still pass with this include (verified).
//   2. The unwind state stores appear only when the free that STLport's
//      allocator calls is declared with a non-nothrow exception specification
//      (`extern "C" void __cdecl free(void *block) throw(...);`) BEFORE the STL
//      headers are included. Declaring it before stdlib.h conflicts
//      (error C2375, stdlib's free is _CRTIMP); the working route is
//      `_INC_STDLIB` plus the full C-stdlib declaration set, as done in
//      Code/Libraries/Source/WWVegas/WWLib/stlport_narrow_money_get_long_double.cpp.
//      Applying `_INC_STDLIB` alone to this TU fails (cstdlib wants div_t etc.),
//      so the next pass must supply that declaration set (or a forced-include
//      header) and then this body becomes byte-exact.
//
// Everything below the file-level levers is the recovered body.

static void updateBuddyStatus( GameSpyBuddyStatus status, Int groupRoom = 0, std::string gameName = "" )
{
	// BFME's BuddyRequest is 0x2B8 bytes, not the shared header's 0x208
	// (GameSpyBuddyMessageQueue::getRequest copies 0xAE dwords vs our 0x82).
	// Keep the tail local so this body reserves retail's 0x2B8 frame without
	// changing the shared donor header for other translation units.
	struct Bfme2BuddyStatusRequest : BuddyRequest
	{
		char m_bfme2Tail[0xB0];
	};

	if (!TheGameSpyBuddyMessageQueue)
		return;

	Bfme2BuddyStatusRequest req;
	req.buddyRequestType = BuddyRequest::BUDDYREQUEST_SETSTATUS;
	switch(status)
	{
		case BUDDY_OFFLINE:
			req.arg.status.status = GP_OFFLINE;
			strcpy(req.arg.status.statusString, "Offline");
			strcpy(req.arg.status.locationString, "");
			break;
		case BUDDY_ONLINE:
			req.arg.status.status = GP_ONLINE;
			strcpy(req.arg.status.statusString, "Online");
			strcpy(req.arg.status.locationString, "");
			break;
		case BUDDY_LOBBY:
			req.arg.status.status = GP_CHATTING;
			strcpy(req.arg.status.statusString, "Chatting");
			sprintf(req.arg.status.locationString, "%d", groupRoom);
			break;
		case BUDDY_STAGING:
			req.arg.status.status = GP_STAGING;
			strcpy(req.arg.status.statusString, "Staging");
			sprintf(req.arg.status.locationString, "%s", gameName.c_str());
			break;
		case BUDDY_LOADING:
			req.arg.status.status = GP_PLAYING;
			strcpy(req.arg.status.statusString, "Loading");
			sprintf(req.arg.status.locationString, "%s", gameName.c_str());
			break;
		case BUDDY_PLAYING:
			req.arg.status.status = GP_PLAYING;
			strcpy(req.arg.status.statusString, "Playing");
			sprintf(req.arg.status.locationString, "%s", gameName.c_str());
			break;
		case BUDDY_MATCHING:
			req.arg.status.status = GP_ONLINE;
			strcpy(req.arg.status.statusString, "Matching");
			strcpy(req.arg.status.locationString, "");
			break;
	}
	DEBUG_LOG(("updateBuddyStatus %d:%s\n", req.arg.status.status, req.arg.status.statusString));
	TheGameSpyBuddyMessageQueue->addRequest(req);
}
