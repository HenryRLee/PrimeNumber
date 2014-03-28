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

inline bool Fermat::IsPrime(mpz_class num)
{
	mpz_class product;
	mpz_class modulo;
	mpz_class sub;

	if ((num % 2) == 0)
	{
		if (num == 2)
			return true;
		else
			return false;
	}

	sub = num - 1;
	mpz_ui_pow_ui(product.get_mpz_t(), 2, sub.get_ui());
	mpz_mod(modulo.get_mpz_t(), product.get_mpz_t(), num.get_mpz_t());

	if (modulo == 1)
		return true;
	else
		return false;
}

bool Fermat::IsPrime(string input)
{
	mpz_class num;

	num = input;

	return IsPrime(num);
}

Fermat::Fermat(void)
{
	name = "Fermat";
}
