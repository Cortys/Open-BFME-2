// ?initReverseAnimateWindow@ProcessAnimateWindowSlideFromRightFast@@UAEXPAVAnimateWindow@@I@Z
// partial score=0.85 date=2026-09-30
// cl: see the parent TU (Code/GameEngine/Source/GameClient/GUI/ProcessAnimateWindow.cpp)
//
// ?initReverseAnimateWindow@ProcessAnimateWindowSlideFromRightFast@@UAEXPAVAnimateWindow@@I@Z
// retail 0x005C631E, 175 bytes. PARTIAL -- not landed. Re-apply this body to its
// class in the parent TU; it is not standalone (AnimateWindow/Coord2D come from
// the real headers).
//
// This is a genuine near miss, not a drifted placement: the compiled size is
// already exactly 175 and the body is byte-identical from 0x5C631E through
// 0x5C6353 and again from 0x5C6386 to the `ret 8` at 0x5C63CC. The whole
// residual is SEVEN instructions in one block, 0x5C6353-0x5C6383, and it is
// pure SSE register allocation plus scheduling:
//
//   target:   movss xmm0,[ebp-8] / movss xmm2,ds:-1.0f / movss xmm1,[ebp-4] /
//             mov ecx,[esi+0x28] / mulss xmm0,xmm2 / movss [ebp-8],xmm0 /
//             mov eax,[ebp-8] / mov [esi+0x2c],eax / mulss xmm1,xmm2 / ...
//   compiled: movss xmm1,[ebp-8] / movss xmm0,ds:-1.0f / mov ecx,[esi+0x28] /
//             mulss xmm1,xmm0 / movss [ebp-8],xmm1 / movss xmm1,[ebp-4] /
//             mov eax,[ebp-8] / mov [esi+0x2c],eax / mulss xmm1,xmm0 / ...
//
// Retail keeps BOTH velocity components live across the first multiply (xmm0 =
// x, xmm1 = y, xmm2 = -1.0f); the compiler reuses xmm1 for x and reloads y from
// [ebp-4] afterwards, so it needs only two registers. Same instructions, same
// order of the stores, same constant, same size -- different allocation.
//
// REFUTED, so the next seat does not respend them. Every one of these produced
// the byte-identical compiled block above:
//   * `vel.x *= -1` / `*= -1.0f` / `vel.x = -1.0f * vel.x` /
//     `vel.x = vel.x * -1.0f` / `(Real)-1` / `vel.x = -vel.x`;
//   * the two statements swapped;
//   * two named locals then assignment;
//   * `for (int i = 0; i < 2; ++i) (&vel.x)[i] *= -1;`
//   * an aggregate `Coord2D nv = { -vel.x, -vel.y }; vel = nv;`
//   * the TU's own flags with `/arch:SSE2`, without `/Oy-`, or with `/Ob2`;
//     `/O2` is WORSE (first diff moves back to +0x2B).
//
// The surrounding source is `Coord2D vel = animWin->getVel(); vel.x *= -1;
// vel.y *= -1; animWin->setVel( vel );` and the `mov ecx,[esi+0x28]` is part of
// the inlined setVel. Getting the allocator to keep three live xmm registers is
// the one thing left; no source spelling tried so far does it.

void ProcessAnimateWindowSlideFromRightFast::initReverseAnimateWindow( AnimateWindow *animWin, UnsignedInt maxDelay )
{
	if(!animWin)
	{
		DEBUG_ASSERTCRASH( animWin, ("animWin was passed into initAnimateWindow as a NULL Pointer... bad bad bad!"));
		return;
	}
	if(animWin->getDelay() > 0)
		animWin->setStartTime(timeGetTime() + (maxDelay - animWin->getDelay()));
	Coord2D vel = animWin->getVel();
	vel.x *= -1;
	vel.y *= -1;
	animWin->setVel( vel );	
	animWin->setFinished( FALSE );
	GameWindow * win = animWin->getGameWindow();
	ICoord2D pos, tempPos;
	win->winGetPosition(&pos.x, &pos.y);
	tempPos = animWin->getCurPos();
	tempPos.y = pos.y;
	animWin->setCurPos(tempPos);

	tempPos = animWin->getEndPos();
	tempPos.y = pos.y;
	animWin->setEndPos(tempPos);

	tempPos = animWin->getStartPos();
	tempPos.y = pos.y;
	animWin->setStartPos(tempPos);




}
