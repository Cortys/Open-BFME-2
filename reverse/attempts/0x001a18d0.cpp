// ?Scale@ParticleEmitterClass@@UAEXM@Z
// partial score=0.99 date=2026-09-27
void ParticleEmitterClass::Scale(float scale)
{
	// Scale all velosity and position parameters
	if (PosRand) PosRand->Scale(scale);
	BaseVel *= scale;
	if (VelRand) VelRand->Scale(scale);
	OutwardVel *= scale;

	// Scale sizes of all particles
	Buffer->Scale(scale);
}
