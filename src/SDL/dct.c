#include <stdio.h>
#include <math.h>
#include "fqcodec.h"
#include "dct.h"
#include "mixfft.h"
#include <malloc.h>
#include <string.h>

#ifndef PI
#define PI		3.14159265358979323846F
#endif

int Initdct(float *buf, udword len) {
	udword i;
	float f;

	for (i = 0; i < len >> 2; i++) {
		f = ((float)i + 0.125f) * (PI * 2.0f) * (1.0f / (float)len);
		buf[i] = sinf(f);
		buf[i + (len >> 2)] = cosf(f);
	}

	return OK;
}

int idct(float *a, float *b, float *c, udword len) {
	udword i;
	//float aa[len], ab[len], ac[len], ad[len], ae[len];
	float * aa = (float *) alloca(sizeof(float) * len);
	float * ab = (float *) alloca(sizeof(float) * len);
	float * ac = (float *) alloca(sizeof(float) * len);
	float * ad = (float *) alloca(sizeof(float) * len);
	float * ae = (float *) alloca(sizeof(float) * len);

	udword hlen = len / 2;
	udword qlen = len / 4;
	udword q3len = qlen * 3;
	float factor = 8.0f / sqrtf(len);

	memset(aa, 0, len << 2);
	memset(ab, 0, len << 2);
	memset(ac, 0, len << 2);
	memset(ad, 0, len << 2);
	memset(ae, 0, len << 2);

	for (i = 0; i < qlen; i++) {
		float x = a[i * 2] * factor * c[i + qlen];
		float w = a[hlen - (i * 2) - 1] * factor * c[i];
		float u = a[i * 2] * factor * c[i] * -1;
		float t = a[hlen - (i * 2) - 1] * factor * c[i + qlen];

		aa[i] = x + w;
		ab[i] = u + t;
	}

	fft(qlen, aa, ab, ac, ad);

	for (i=0; i < qlen; i++) {
		float y = ac[i] * c[i + qlen];
		float x = ad[i] * c[i];
		float v = ac[i] * c[i] * -1;
		float u = ad[i] * c[i + qlen];

		ac[i] = (y + x) * factor;
		ad[i] = (v + u) * factor;
	}

	for (i = 0; i < qlen; i++) {
		ae[i * 2] = ac[i];
		ae[hlen + (i * 2)] = ad[i];
	}

	for (i = 1; i < len; i += 2) {
		ae[i] = ae[len - i - 1] * -1;
	}

	i = 0;

	while (i < q3len) {
		b[i] = ae[i + qlen];
		i++;
	}

	while (i < len) {
		b[i] = ae[i - q3len] * -1;
		i++;
	}

	return OK;
}
