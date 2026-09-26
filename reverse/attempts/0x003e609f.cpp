// evaluatePlayerHasNumberUnitsDistanceFromObject
// partial score=0.58 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// Target template 161 is PLAYER_HAS_NUMBER_UNITS_DISTANCE_FROM_OBJECT.
// Retail 0x003E609F consumes five Parameter pointers in player, comparison,
// count, distance, named-object order and calls the Team-member callback at
// 0x003E6032 while iterating each player selected by the player mask.

typedef bool Bool;
typedef unsigned int PlayerMask;

class Parameter
{
public:
    unsigned char m_beforeInt[8];
    int m_int;
    float m_real;
    unsigned char m_beforeString[16];
    int m_cachedMask;
};

class Object;
struct DistanceCountContext
{
    float x, y, z;
    float distanceSquared;
    int count;
    int stopAfter;
};

typedef Bool (__cdecl *ObjectDistanceCallback)(
    Object *, DistanceCountContext *, Bool);

class Player
{
public:
    Bool applyToTeamMembersUntil(ObjectDistanceCallback callback,
                                 DistanceCountContext *context);
};

class PlayerList
{
public:
    Player *getEachPlayerFromMask(PlayerMask &mask);
};

class ScriptEngine
{
public:
    PlayerMask getPlayerMask(Parameter *parameter);
    Object *getUnitNamed(Parameter *parameter);
};

class Object
{
public:
    unsigned char m_beforePosition[0x38];
    float m_position[3];

    Bool isCountableForDistanceCondition(Bool includeContained, Bool includeDead);
};

class ScriptConditions
{
protected:
    Bool evaluatePlayerHasNumberUnitsDistanceFromObject(
        Parameter *, Parameter *, Parameter *, Parameter *, Parameter *);
};

#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
#define ThePlayerList (*(PlayerList **)0x00DFEEE8)

Bool __cdecl ObjectDistanceFromNamedObject(
    Object *object, DistanceCountContext *context, Bool includeContained)
{
    if (!object->isCountableForDistanceCondition(includeContained, false))
        return true;

    const float dx = object->m_position[0] - context->x;
    const float dy = object->m_position[1] - context->y;
    const float dz = object->m_position[2] - context->z;
    if (dx * dx + dy * dy + dz * dz > context->distanceSquared)
        ++context->count;
    return context->count <= context->stopAfter;
}

Bool ScriptConditions::evaluatePlayerHasNumberUnitsDistanceFromObject(
    Parameter *playerParm, Parameter *comparisonParm, Parameter *countParm,
    Parameter *distanceParm, Parameter *objectParm)
{
    PlayerMask mask = TheScriptEngine->getPlayerMask(playerParm);
    if (!mask)
        return false;

    DistanceCountContext context;
    const float distance = distanceParm->m_real < 0.0f ? 0.0f : distanceParm->m_real;
    context.distanceSquared = distance * distance;
    context.count = 0;
    context.stopAfter = countParm->m_int;

    Object *center = TheScriptEngine->getUnitNamed(objectParm);
    if (center) {
        context.x = center->m_position[0];
        context.y = center->m_position[1];
        context.z = center->m_position[2];
    } else {
        context.x = context.y = context.z = 0.0f;
        context.distanceSquared = -1.0f;
    }

    for (Player *player = ThePlayerList->getEachPlayerFromMask(mask);
         player != 0;
         player = ThePlayerList->getEachPlayerFromMask(mask)) {
        if (!player->applyToTeamMembersUntil(
                &ObjectDistanceFromNamedObject, &context))
            break;
        if (context.count > context.stopAfter)
            break;
    }

    switch (comparisonParm->m_int) {
    case 0: return context.count < countParm->m_int;
    case 1: return context.count <= countParm->m_int;
    case 2: return context.count == countParm->m_int;
    case 3: return context.count >= countParm->m_int;
    case 4: return context.count > countParm->m_int;
    case 5: return context.count != countParm->m_int;
    default: return false;
    }
}
