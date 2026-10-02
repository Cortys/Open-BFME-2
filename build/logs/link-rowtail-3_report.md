# Link rowtail round 3 report

## `Code/GameEngine/Source/GameClient/FXParticleSystemFactories.cpp`

**Shared cause found for the draw-template destructors:** this TU flattened
`RenderObjectDrawModuleTemplate` and `GpuDrawModuleTemplate` into direct
`ModuleTemplate`/`SecondaryModuleBase`/info bases, while retail routes both
through `CategoryModuleTemplate<6>`. The TU also lacked visible trivial
destructor bodies for the two common bases. Restoring the intermediate base
view and making those bodies visible lets MSVC 7.1 emit the retail EH-state and
base-vptr teardown sequence.

- `??1GpuDrawModuleTemplate@FXParticleSystem@@UAE@XZ` at `0x003A9E80` —
  **repaired**, 10B → 71B. Ghidra gives 71B and the next constructor begins at
  `0x003A9EC7`; the full 71-byte comparison is exact.
- `??1RenderObjectDrawModuleTemplate@FXParticleSystem@@UAE@XZ` at
  `0x003A9C39` — **repaired**, 10B → 71B. Ghidra gives 71B and the next
  constructor begins at `0x003A9C80`; the full 71-byte comparison is exact.
- `??1LifeEventModuleTemplate@FXParticleSystem@@UAE@XZ` at `0x003AA0C0` —
  source now compiles to the exact 71-byte retail body. **Row not re-landed**:
  `add_match.py --replace-existing` refuses because the existing
  `TerrainCollisionModuleTemplate` row claims the same RVA.
- `??1TerrainCollisionModuleTemplate@FXParticleSystem@@UAE@XZ` at
  `0x003AA0C0` — **not repaired/re-landed**. The 71-byte retail body calls
  `0x003A9F8A`; this TU's emitted call to
  `??1TerrainCollisionModuleInfo@FXParticleSystem@@UAE@XZ` remains unresolved.
  The call displacement begins at `+0x1F`. No alias/pin was added without
  verified identity evidence. Its existing same-RVA row also blocks safely
  re-landing the LifeEvent alias.
- `?createTemplate@?$ConcreteModuleClass@V?$DefaultModuleTag@$06@FXParticleSystem@@@FXParticleSystem@@UBEPAV?$DefaultModuleTemplate@$06@2@XZ`
  at `0x003AC7A5` — **not repaired**, 10B remains. Retail extent 50B; compiled
  section 50B. First difference `+0x0C`: retail allocates `0x50`, source emits
  `0x54`. The class-size/base-layout cause remains unresolved.
- `?createTemplate@?$ConcreteModuleClass@V?$DefaultModuleTag@$06@FXParticleSystem@@@FXParticleSystem@@UBEPAV?$DefaultModuleTemplate@$06@2@PAVINI@@@Z`
  at `0x003AC757` — **not repaired**, 10B remains. Retail extent 78B; compiled
  section 78B. First difference `+0x0D`: allocation immediate `0x50` vs
  `0x54`; the compiled `DefaultModuleTemplate<6>::parse` call is also unresolved.
- `?createTemplate@...PointEmissionVolumeModuleTag...` at `0x003AB3D5` —
  **not repaired**, 10B remains; retail 71B, compiled 78B, first difference
  `+0x13` (`test eax,eax` in retail vs `pop ecx` in the compiled body).
- `?createTemplate@...BOX_EMISSION_VOLUME_MODULE...` at `0x003AB4E5` —
  **not repaired**, 10B remains; retail 71B, compiled 78B, first difference
  `+0x13` with the same null-check/stack-cleanup ordering.
- `?createTemplate@...CYLINDER_EMISSION_VOLUME_MODULE...` at `0x003AB5F5` —
  **not repaired**, 10B remains; retail 71B, compiled 78B, first difference
  `+0x13` with the same null-check/stack-cleanup ordering.
- `?createTemplate@...LINE_EMISSION_VOLUME_MODULE...` at `0x003AB45D` —
  **not repaired**, 10B remains; retail 71B, compiled 78B, first difference
  `+0x13` with the same null-check/stack-cleanup ordering.
- `?createTemplate@...SPHERE_EMISSION_VOLUME_MODULE...` at `0x003AB56D` —
  **not repaired**, 10B remains; retail 71B, compiled 78B, first difference
  `+0x13` with the same null-check/stack-cleanup ordering.

The one `reset(new T)` and one raw-pointer/`auto_ptr` shaping trials did not
change the five factory bodies; both trials were reverted. No other factory
row was shortened or retracted.

Validation after the retained FX change: `./build.sh
Code/GameEngine/Source/GameClient/FXParticleSystemFactories.cpp` passed
66/66; `tools/check_csv.py` passed; `find_declared_unmatched.py --fail`
reported all definitions matched; `class_gate.py` passed silently.
