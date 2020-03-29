//Jared VanEnkevort
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
#include "LLStack.h"
using namespace std;

string LLStack::getName()
{
	return name;
}

LLStack::LLStack(string input) {
	name = input;
	head = NULL;
}

LLStack::~LLStack() {

	delete head;
}

void LLStack::PUSH(int s) {

	head = new StackNode(s, head);
}

int LLStack::POP() {
	if (ISEMPTY()) {
		return -10;
	}
	else {
		StackNode* h = head;
		head = h->getnext();
		h->setnext(NULL);
		int s = h->getS();
		delete h;
		return s;
	}
}

bool LLStack::ISEMPTY() {

	return !head;
}

