// cl: /O2 /MD
// May 2006 Xbox APT0.19.03 PDB supplies member names and class identity.
// Target startup 7B67A0 constructs global VA E182E0 with 6FE980, then registers
// cleanup 7B9C50, which passes the same global to destructor 6FE9C0. That
// destructor and AptActionInterpreter.cpp assertion caller 6FEB50 operate on
// debugCallStack at +34 (see AptInterpreterDebugStack.cpp).
// Target independently establishes zero initialization of five 12-byte stacks
// at 0/C/18/24/34, leaving +30 alone. Only the accessed prefix is modeled;
// donor names/types describe the stack roles, not a recovered full class ABI.
class AptValue;
class AptScriptFunctionBase;
template<class T> struct AptCtorStackView {
    int count, capacity;
    T **elements;
    AptCtorStackView() : count(0), capacity(0), elements(0) {}
};
struct AptActionInterpreter {
    struct DebugCallStackInfo_t;
    AptCtorStackView<AptValue> stack, withStack, setTargetStack, thisStack;
    AptScriptFunctionBase *mpCurrentFunction;
    AptCtorStackView<DebugCallStackInfo_t> debugCallStack;
    AptActionInterpreter();
};
AptActionInterpreter::AptActionInterpreter() {}
