// ?Rva002E17D6Partition@@YAXPAPAX0PAX1@Z
// partial score=0.93 date=2026-09-29
// ?Rva002E17D6Partition@@YAXPAPAX0PAX1@Z
// partial score=0.93 date=2026-09-29
// cl: /O1
//
// ?Rva002E17D6Partition@@YAXPAPAX0PAX1@Z @0x002E17D6 55B.
// Hoare partition over pointer array keyed at +0xC with pivot object.
// Evidence: caller 0x002E2CBD passing begin end pivot extra; prev/next /O1.
void Rva002E17D6Partition(void **begin, void **end, void *pivotObj, void *unused)
{
	for (;;) {
		int pivot = ((int *)pivotObj)[3];
		for (;;) {
			void *cur = *begin;
			if (((int *)cur)[3] > pivot)
				break;
			++begin;
		}
		do {
			--end;
		} while (pivot > ((int *)(*end))[3]);
		if (begin >= end)
			return;
		void *tmp = *begin;
		*begin = *end;
		*end = tmp;
		++begin;
	}
}
