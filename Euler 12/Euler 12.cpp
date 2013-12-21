// Euler 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimeLister.h"
#include "Euler 12.h"


int _tmain(int argc, _TCHAR* argv[])
{
	PrimeLister thePrimes;
	TriangleNumber temp;
	unsigned long long answer = -1;	// The whole fucking reason we are here
	
	/*
	// Testing Crap
	cout << "Just a testaroni of PrimeLister. The primes found are:\n" << thePrimes.toString() << endl;
	thePrimes.isItPrime(5000);
	cout << "Now thePrimes are:\n" << thePrimes.toString() << endl;

	for (int i = 0; i < 10; i++) {
		cout << temp.currentNumber() << endl;
		temp.next();
	}
	*/
	do {
		temp.next();
		cout << "Checking " << temp.currentNumber() << endl;
		answer = countTheFactors(&thePrimes, temp.currentNumber());
	} while (answer < 500 && answer > 0);

	cout << "The answer is: " << temp.currentNumber() << endl;
	cout << "It has " << answer << " factors." << endl;

	system("PAUSE");
	return 0;
}

// TriangleNumber
TriangleNumber::TriangleNumber() {
	value = 1;
	iter = 1;
}

bool TriangleNumber::next() {
	value += ++iter;

	// Don't kow how this would fail...
	return true;
}

// FactorList
FactorList::FactorList() {
	head = NULL;
	tail = NULL;
	cur = NULL;
}
FactorList::~FactorList() {
	clearList();
}

void FactorList::addFactor(unsigned long long f, int e) {
	if (head == NULL) {
		head = new FactorNode(f, e);
		tail = head;
		cur = head;
	}
	else {
		tail->next = new FactorNode(f, e);
		tail = tail->next;
	}
}

int FactorList::nextFactor() {
	if (cur == tail || cur->next == NULL) {
		return -1;
	}

	cur = cur->next;
	return 1;
}

void FactorList::clearList() {
	FactorNode *tempy;
	while (head != NULL) {
		tempy = head;
		head = head->next;
		delete tempy;
	}
}

unsigned long long countTheFactors(PrimeLister *list, unsigned long long num) {
	/* This doesn't short circuit program
	
	// Is it prime? 
	if (list->isItPrime(num)) {
		return 2;
	}
	*/
	FactorList primeFacts;

	// Find the factors
	list->resetCur();
	while (num > 1) {
		unsigned long long cur = list->popAPrime();
		if (cur == 0) {
			list->nextPrime();
			cur = list->popAPrime();
		}
		int i = 0;
		while (num % cur == 0) {
			num = num / cur;
			i++;
		}
		if (i > 0) {
			primeFacts.addFactor(cur, i);
		}
	}

	unsigned long long ans = 1;

	primeFacts.resetCur();

	do {
		ans *= primeFacts.curExp() + 1;
	} while (primeFacts.nextFactor() > 0);

	return ans;

}