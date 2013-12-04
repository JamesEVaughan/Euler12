#pragma once
// And for our non-Visual Studio friends out there...
#ifndef PRIMELISTER_H
#define PRIMELISTER_H

#include "stdafx.h"

class PrimeLister;

// PrimeNode is a node in the list controller by PrimeLister
class PrimeNode {
	friend class PrimeLister;
public:
	// Constructor
	PrimeNode(unsigned long long val, PrimeNode *ptr = NULL);

private:
	unsigned long long prime;	// The prime number stored in this list
	PrimeNode *next;			// Next node in list
};

// PrimeLister is a singly linked list of the primes in squential order
class PrimeLister
{
public:
	PrimeLister();
	~PrimeLister();

	// Builds PrimeNodes until ceil is reached, negative if error
	//unsigned long long findPrimes(unsigned long long ceil);

	// Finds and adds the next prime, negative if error
	unsigned long long nextPrime();

	// Output functions
	string toString();

private:
	// The list
	PrimeNode *head;	// Head of the list
	PrimeNode *tail;	// Tail of the list


	// Helper methods
	unsigned long long biggestPrime();	// Biggest prime found, last->value

	// Adds next PrimeNode
	unsigned long long addNode(unsigned long long prime);

	// Deletes entire list, helper for deconstructor
	void deleteList();

};


#endif