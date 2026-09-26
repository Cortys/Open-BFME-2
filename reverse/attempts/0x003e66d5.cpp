// ?evaluateNamedInsideAreaThunk@ScriptConditions@@IAE_NPAVParameter@@0@Z
// partial score=0.88 date=2026-09-26
// ?evaluateNamedInsideAreaThunk@ScriptConditions@@IAE_NPAVParameter@@0@Z
// cl: /DNDEBUG /MD /EHsc /O2
// BFME1 donor: ScriptConditionsNamedInsideAreaThunk.cpp.
class Parameter;
class ScriptConditions
{
protected:
    __declspec(noinline) int evaluateNamedInsideArea(Parameter *, Parameter *);
    bool evaluateNamedInsideAreaThunk(Parameter *, Parameter *);
};

bool ScriptConditions::evaluateNamedInsideAreaThunk(
    Parameter *unit, Parameter *trigger)
{
    return evaluateNamedInsideArea(unit, trigger);
}
