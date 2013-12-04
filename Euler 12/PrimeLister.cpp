#include "StdAfx.h"
#include "PrimeLister.h"

// PrimeLister
PrimeLister::PrimeLister() {
	// Start with first two primes to make findPrimes() easier
	head = new PrimeNode(2);
	tail = head;
	addNode(3);

	for (int i = 2; i < 20; i++) {
		nextPrime();
	}
}

PrimeLister::~PrimeLister() {
	deleteList();
}

unsigned long long PrimeLister::addNode(unsigned long long prime) {
	PrimeNode *tempy = new PrimeNode(prime);
	if (tempy == NULL) {
		return -1;
	}
	tail->next = tempy;
	tail = tempy;

	return 1;
}

unsigned long long PrimeLister::nextPrime() {
	unsigned long long tempy = tail->prime;
	static unsigned long long root = 2;
	bool primeFound = false;
	PrimeNode *cur;

	while (!primeFound) {
		tempy += 2;
		// Is root too small?
		if (root * root < tempy) {
			root++;
		}
		cur = head;
		while (cur != NULL) {
			if (tempy % cur->prime) {
				cur = cur->next;
			}
			else {
				break;
			}
		}

		if (cur == NULL) {
			tail->next = new PrimeNode(tempy);
			primeFound = true;
		}
	}

	// Errorchecking
	if (tail->next == NULL) {
		return -1;
	}

	tail = tail->next;
	return tail->prime;
}

void PrimeLister::deleteList() {
	PrimeNode *tempy;
	while (head != NULL) {
		tempy = head->next;
		delete head;
		head = tempy;
	}
}

unsigned long long PrimeLister::biggestPrime() {
	return tail->prime;
}

string PrimeLister::toString() {
	PrimeNode *cur = head;
	string tempy;

	// Special cases
	// Empty list
	if (cur == NULL) {
		return "";
	}
	// One item list
	if (cur->next == NULL) {
		return to_string(cur->prime);
	}

	// Prime the pump
	tempy = to_string(cur->prime);

	while (cur != NULL) {
		tempy += ", " + to_string(cur->prime);
		cur = cur->next;
	}

	return tempy;
}

// PrimeNode
PrimeNode::PrimeNode(unsigned long long val, PrimeNode *ptr) {
	prime = val;
	next = ptr;
}