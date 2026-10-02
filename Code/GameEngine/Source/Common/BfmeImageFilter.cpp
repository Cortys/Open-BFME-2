// cl: /EHsc
#include <excpt.h>

// ?bfmeProbeSse2@@YAHXZ
int __cdecl bfmeProbeSse2(void)
{
	// Retail's SEH funclets read the exception code into and back out of this
	// local before the handler returns zero.
	volatile unsigned int code;
	__try {
		__asm { xorpd xmm0, xmm0 }
	} __except ((code = *(*(unsigned int **)GetExceptionInformation()),
			EXCEPTION_EXECUTE_HANDLER)) {
		(void)code;
		return 0;
	}
	return 1;
}
