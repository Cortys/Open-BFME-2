// ?onDie@StructureCollapseUpdate@@UAEXPBVDamageInfo@@@Z
// partial score=0.96 date=2026-09-27
// needs: /Ireference/shims/dockupdate (UpdateModule +0x1C dword; fixes all this-adjusts), Object m_ai at +0x258, PLAYERMASK_ALL=0xfffff as a 32-bit PlayerMaskType arg to deselectObject
void StructureCollapseUpdate::onDie( const DamageInfo *damageInfo )
{
	const StructureCollapseUpdateModuleData* d = getStructureCollapseUpdateModuleData();
	if (!d->m_dieMuxData.isDieApplicable(getObject(), damageInfo))
		return;

	AIUpdateInterface *ai = getObject()->getAIUpdateInterface();
	if (ai)
		ai->markAsDead();

	// deselect this object for all players.
	TheGameLogic->deselectObject(getObject(), PLAYERMASK_ALL, TRUE);

	beginStructureCollapse(damageInfo);
}
