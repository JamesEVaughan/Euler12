// Header for the Euler 12 program. Mainly contains a helper class.

#include "stdafx.h"
#include "PrimeLister.h"

class TriangleNumber {
	// Just a little class to handle creation of triangle numbers
	// The numbers are generated in sequence
private:
	unsigned long long value;	// Current triangle number found
	int iter;					// Current iteration

public:
	TriangleNumber();

	bool next();	// Generates next triangle number in sequence, false if failed
	// Accessors
	unsigned long long currentNumber() {return value;}
	int currentIteration() {return iter;}
};

class FactorList {
private:
	class FactorNode {
		friend class FactorList;
	private:
		unsigned long long factor;
		int exp;
		FactorNode *next;
	public:
		FactorNode(unsigned long long f, int e) {
			factor = f;
			exp = e;
			next = NULL;
		}
	};

	FactorNode *head;
	FactorNode *tail;
	FactorNode *cur;

public:
	FactorList();
	~FactorList();

	void addFactor(unsigned long long f, int e);
	int curExp() {return cur->exp;}
	unsigned long long curFactor() {return cur->factor;}
	int nextFactor();
	void resetCur() {cur = head;}
	void clearList();
};

unsigned long long countTheFactors(PrimeLister *list, unsigned long long num);