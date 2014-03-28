/*
 * PrimalityTest.cpp for PrimeNumber
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

#include "PrimalityTest.h"
#include "Fermat.h"
#include "Trial.h"

Algorithm * trial = new Trial;
Algorithm * fermat = new Fermat;

Algorithm * alCurrent;

bool PrimalityTest(Algorithm * algorithm, string input)
{
	return algorithm->IsPrime(input);
}

void ChangeAlgorithm(Algorithm * algorithm)
{
	alCurrent = algorithm;

	cout << "Current algorithm is " << alCurrent->name << endl;
}

void Interface(void)
{
	string input;

	cout << "> ";
	cin >> input;

	if ((input.compare("h") == 0) || (input.compare("help") == 0))
	{
		cout << "Available commands:" << endl;
		cout << "\t[h]elp  " << "\t\tHelp" << endl;
		cout << "\t[f]ermat" << "\t\tChoose Fermat algorithm" << endl;
		cout << "\t[t]rial " << "\t\tChoose Trial Division algorithm" << endl;
		cout << "\t[q]uit  " << "\t\tQuit" << endl;
		cout << "\t<number>" << "\t\tThe number in test" << endl;

		Interface();
	}
	else if ((input.compare("f") == 0) || (input.compare("fermat") == 0))
	{
		ChangeAlgorithm(fermat);
		Interface();
	}
	else if ((input.compare("t") == 0) || (input.compare("trial") == 0))
	{
		ChangeAlgorithm(trial);
		Interface();
	}
	else if ((input.compare("q") == 0) || (input.compare("quit") == 0))
	{
		exit(0);
	}
	else
	{
		bool isnumber = true;
		for (int i=0; i<input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				cout << "Unknown command. Try h for help" << endl;
				isnumber = false;
				break;
			}
		}
		if (isnumber)
		{
			if (alCurrent->IsPrime(input))
				cout << input << " is a prime" << endl;
			else
				cout << input << " is not a prime" << endl;
		}

		Interface();
	}
}

int main(int argc, char *argv[])
{
	ChangeAlgorithm(fermat);

	Interface();	

	return 0;
}
