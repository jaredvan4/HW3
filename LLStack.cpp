//Jared VanEnkevort
//contains the function definitions for the prototypes present in LLStack.h

#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
#include "LLStack.h"
using namespace std;

int LLStack::getNum()
{
	return num;
}

LLStack::LLStack() {
	head = NULL;
	num = NULL;
}

LLStack::~LLStack() {
	delete head;
}
LLStack::LLStack(int newNum) {
	head = NULL;
	num = newNum;
}

void LLStack::PUSH(int s) {

	head = new StackNode(s, head);
}

int LLStack::POP() {
		StackNode* h = head;
		head = h->getnext();
		h->setnext(NULL);
		int s = h->getS();
		delete h;
		return s;
}

bool LLStack::ISEMPTY() {

	return !head;
}

