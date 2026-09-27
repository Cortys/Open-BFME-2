/*
 * Adapted from libtheora 1.0alpha2, lib/dct_decode.c, CopyBlock.
 * Copyright (c) 2002, Xiph.org Foundation. See COPYING in this directory.
 * Donor provenance: exact source body and signature from libtheora.
 * Target evidence: retail routine at RVA 0x001B7F30 copies eight rows of
 * eight bytes using the supplied source/destination stride.
 */
typedef unsigned int ogg_uint32_t;

void CopyBlock(unsigned char *src, unsigned char *dest, unsigned int srcstride)
{
	unsigned char *s = src;
	unsigned char *d = dest;
	unsigned int stride = srcstride;
	int j;

	for (j = 0; j < 8; j++) {
		((ogg_uint32_t *)d)[0] = ((ogg_uint32_t *)s)[0];
		((ogg_uint32_t *)d)[1] = ((ogg_uint32_t *)s)[1];
		s += stride;
		d += stride;
	}
}
