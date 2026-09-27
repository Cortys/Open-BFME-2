// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG
// ??RParabolicEase@@QBEMM@Z, retail 0x0030E5D1, 171 bytes.
// ParabolicEase::operator() -- ease in/out based on parabolic function.
// Donor: BFME1 Code/GameEngine/Source/GameClient/ParabolicEase.cpp (return-style clamp)
//   and ZH reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source/GameClient/ParabolicEase.cpp
//   (ParabolicEase.h: m_in/m_out, Real operator()(Real) const).
// Evidence: clamp-then-piecewise shape matches donor verbatim (denominator 1+m_out-m_in,
//   t<t branch t*t/(den*m_in), t<=b branch (m_in+2*(t-m_in))/den,
//   else (m_in+2*(m_out-m_in)+(2*(t-m_out)+m_out*m_out-t*t)/(1-m_out))/den);
//   landing unblocks 7 callers (0x00086C4A/0x00086CDA/0x00086D73/0x00086E24/0x00086EBD/0x00086F56/0x00089ED4)
//   that lerp with its result; 1.0f global at 0x00BBB8D8.
typedef float Real;
class ParabolicEase
{
public:
	void setEaseTimes(Real easeInTime, Real easeOutTime);
	Real operator()(Real param) const;
private:
	Real m_in;
	Real m_out;
};
Real ParabolicEase::operator()(Real param) const
{
	if (param < 0.0f || param > 1.0f) {
		if (param < 0.0f) {
			param = 0.0f;
		} else if (param > 1.0f) {
			param = 1.0f;
		}
	}
	const Real denominator = 1.0f + m_out - m_in;
	if (param < m_in) {
		return param * param / (denominator * m_in);
	} else if (param <= m_out) {
		return (m_in + 2.0f * (param - m_in)) / denominator;
	} else {
		return (m_in + 2.0f * (m_out - m_in) + (2.0f * (param - m_out) + m_out * m_out - param * param) / (1.0f - m_out)) / denominator;
	}
}
