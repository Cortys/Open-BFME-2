// ?Get_Translation@HRawAnimClass@@UBEXAAVVector3@@HM@Z
// partial score=0.5 date=2026-10-04
// ?Get_Translation@HRawAnimClass@@UBEXAAVVector3@@HM@Z @ 0x0018D730 (1570B), banked near miss.
// Needs reference/shims/bfmehrawanim/motchan.h set_identity to store 1.0f for
// Type 15 (ANIM_CHANNEL_FADE) before the ANIM_CHANNEL_Q test (retail evidence).
// Built inside Code/Libraries/Source/WWVegas/WW3D2/hrawanim.cpp: 1468B vs 1570B;
// frame0 half matches in shape, frame1 half differs in register allocation/cold-block layout.
void HRawAnimClass::Get_Translation(Vector3& trans, int pividx, float frame ) const
{
	struct NodeMotionStruct * motion = &NodeMotion[pividx];

	if ( (motion->X == NULL) && (motion->Y == NULL) && (motion->Z == NULL) ) {
		 trans.Set(0.0f,0.0f,0.0f);
		return;
	}

//	int frame0 = (int)frame;
	int frame0=WWMath::Float_To_Long(frame-0.499999f);

	int frame1 = frame0 + 1;

	float ratio = frame - (float)frame0;
	WWASSERT( (ratio >= -WWMATH_EPSILON) && (ratio < 1.0f + WWMATH_EPSILON) );

	if ( frame1 >= NumFrames ) {
		frame1 = 0;
	}

	Vector3 trans0(0.0f,0.0f,0.0f);

	if (motion->X != NULL) {
		motion->X->Get_Vector((int)frame0,&(trans0[0]));
	}
	if (motion->Y != NULL) {
		motion->Y->Get_Vector((int)frame0,&(trans0[1]));
	}
	if (motion->Z != NULL) {
		motion->Z->Get_Vector((int)frame0,&(trans0[2]));
	}

	if ( ratio == 0.0f ) {
		trans=trans0;
		return;
	}

	Vector3 trans1(0.0f,0.0f,0.0f);

	if (motion->X != NULL) {
		motion->X->Get_Vector((int)frame1,&(trans1[0]));
	}
	if (motion->Y != NULL) {
		motion->Y->Get_Vector((int)frame1,&(trans1[1]));
	}
	if (motion->Z != NULL) {				
		motion->Z->Get_Vector((int)frame1,&(trans1[2]));
	}

	Vector3::Lerp( trans0, trans1, ratio, &trans );
}
