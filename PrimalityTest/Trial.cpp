/*
 * Trial.cpp for PrimeNumber
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

#include "Trial.h"
#include <stdlib.h>
#include <math.h>

inline bool Trial::IsPrime(long long num)
{
	int divisor;
	int squareroot;

	if ((num % 2) == 0)
	{
		if (num == 2)
			return true;
		else
			return false;
	}

	squareroot = sqrt(num);
	divisor = 3;

	while (divisor <= squareroot)
	{
		/* Last digit is 3 */
		if (num % divisor == 0)
			return false;

		divisor += 4;

		/* Last digit is 7 */
		if (num % divisor == 0)
			return false;

		divisor += 2;

		/* Last digit is 9 */
		if (num % divisor == 0)
			return false;

		divisor += 2;

		/* Last digit is 1 */
		if (num % divisor == 0)
			return false;

		divisor += 2;
	}

	return true;
}

bool Trial::IsPrime(string input)
{
	return IsPrime(atoll(input.c_str()));
}

Trial::Trial(void)
{
	name = "Trail";
}
