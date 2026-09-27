/*
 * Adapted from libtheora 1.0alpha2, lib/idct.c, IDct1.
 * Copyright (c) 2002, Xiph.org Foundation. See COPYING in this directory.
 * Donor provenance: exact source body and signature from libtheora.
 * Target evidence: retail routine at RVA 0x001D6C60 has the matching DC-only
 * inverse-transform operations and writes one value to 64 output samples.
 */
typedef short ogg_int16_t;
typedef int ogg_int32_t;
typedef short Q_LIST_ENTRY;

void IDct1(Q_LIST_ENTRY *InputData, ogg_int16_t *QuantMatrix,
	   ogg_int16_t *OutputData)
{
	int loop;
	ogg_int16_t OutD;

	OutD = (ogg_int16_t)((ogg_int32_t)(InputData[0] * QuantMatrix[0] + 15) >> 5);

	for (loop = 0; loop < 64; loop++)
		OutputData[loop] = OutD;
}
