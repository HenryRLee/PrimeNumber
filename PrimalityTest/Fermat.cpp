/*
 * Fermat.cpp for PrimeNumber
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Henry Lee
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "Fermat.h"

unsigned long long Fermat::FastModExp(unsigned long long exp,
		unsigned long long mod)
{
	if (exp == 0)
	{
		return (1 % mod);
	}
	else if (exp == 1)
	{
		return (2 % mod);
	}
	else
	{
		unsigned long long sub;
		unsigned long long ret;

		sub = FastModExp(exp/2, mod);

		ret = (sub * sub * (1 << (exp % 2))) % mod;

		return ret;
	}
}

inline bool Fermat::IsPrime(unsigned long long num)
{
	unsigned modulo;

	if (num == 2)
		return true;

	if (num % 2 == 0)
		return false;

	modulo = FastModExp(num-1, num);

	if (modulo == 1)
		return true;
	else
		return false;
}

bool Fermat::IsPrime(string input)
{
	unsigned long long num;

	num = stoll(input);

	return IsPrime(num);
}

Fermat::Fermat(void)
{
	name = "Fermat";
}
