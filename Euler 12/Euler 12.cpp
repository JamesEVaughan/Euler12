// Euler 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimeLister.h"


int _tmain(int argc, _TCHAR* argv[])
{
	PrimeLister thePrimes;

	cout << "Just a testaroni of PrimeLister. The primes found are:\n" << thePrimes.toString() << endl;

	system("PAUSE");
	return 0;
}

