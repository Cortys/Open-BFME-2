// ?On_Frame_Update@ParticleBufferClass@@UAEXXZ
// partial score=0.98 date=2026-09-27
void ParticleBufferClass::On_Frame_Update(void)
{
	WWPROFILE("ParticleBufferClass::On_Frame_Update");
	Invalidate_Cached_Bounding_Volumes();
	if (Emitter) {
		Emitter->Emit();
	}
	
	if (Is_Complete()) {
		WWASSERT(Scene);
		Scene->Register(this,SceneClass::RELEASE);
	}
}
