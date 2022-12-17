#pragma once

namespace Varparm {

	int ivarparm(int n, ...)
	{
		int* p = &n;
		int k = 1;
		for (int i = 1; i <= n; i++)
			k *= *(++p);
		return k;
	}
	int svarparm(short n, ...) {

		int* p = (int*)(&n);
		short k = SHRT_MIN;
		p++;
		for (int i = 1; i <= n; i++, *(p++)) {
			if (*(p) > k)
				k = *(p);
		}
		return k;
	}
	double fvarparm(float n, ...) {
		double* p = (double*)(&n+1);
		int k = 0;
		double sum = 0;
		while (p[k] != (double)FLT_MAX) {
			sum += p[k];
			k++;
		}
		return sum;
	}
	double dvarparm(double n, ...) {
		double* p = &n;
		double sum = 0;
		while (*p != DBL_MAX) {
			sum += *p;
			p++;
		}
		return sum;
	}
}