// ?bfmeRelativeAngleTo@Thing@@QBEMPBUCoord3D@@@Z
// partial score=0.99 date=2026-09-28
// ?bfmeRelativeAngleTo@Thing@@QBEMPBUCoord3D@@@Z
// partial score=0.99 date=2026-09-28
// cl: /O1 /arch:SSE2
// ?bfmeRelativeAngleTo@Thing@@QBEMPBUCoord3D@@@Z @0x000B4542 273B
// BFME1 donor Code/GameEngine/Source/Common/Thing/Thing_bfmeRelativeAngleTo.cpp (matched 214B at 0x00150510)
// Thing via getUnitDirectionVector2D pin 0x0030A25F + m_cachedPos at +0x38/+0x3c (BFME2 FloatUpdate +0x38 precedent)
// Callers 0x000B788A 0x000CC9A8 0x001E9BFC; pooled 0.0f 0x007BAEAC 1.0f 0x007BB8D8 -1.0f 0x007BB9AC dbl -1.0 0x007C9CB8
// Flags from Coord2D::toAngle /O1 /arch:SSE2 sibling (EBP frame + SSE float + x87 double + E8 sqrt thunk)
typedef float Real;
extern Real ACos(Real);
extern "C" double sqrt(double value);
struct Coord3D { Real x; Real y; Real z; };
class Thing {
public:
  const Coord3D *getUnitDirectionVector2D() const;
  Real bfmeRelativeAngleTo(const Coord3D *point) const;
private:
  unsigned char m_pad000[0x38];
  Coord3D m_cachedPos;
};
// ?bfmeRelativeAngleTo@Thing@@QBEMPBUCoord3D@@@Z present-unmatched
Real Thing::bfmeRelativeAngleTo(const Coord3D *point) const
{
  Coord3D delta;
  delta.x = point->x - m_cachedPos.x;
  delta.y = point->y - m_cachedPos.y;
  Real distance = (Real)sqrt(delta.x * delta.x + delta.y * delta.y);
  if (distance == 0.0f)
    return 0.0f;
  Real scale = 1.0f / distance;
  delta.x *= scale;
  delta.y *= scale;
  const Coord3D *direction = getUnitDirectionVector2D();
  Real cosine = direction->x * delta.x;
  cosine += direction->y * delta.y;
  if (cosine < -1.0)
    cosine = -1.0f;
  else if (cosine > 1.0)
    cosine = 1.0f;
  Real angle = ACos(cosine);
  if (direction->x * delta.y - direction->y * delta.x < 0.0f)
    angle = -angle;
  return angle;
}
