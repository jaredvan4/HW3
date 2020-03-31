//Jared VanEnkevort
//contains the function definitions for the prototypes present in LLStack.h

#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
#include "LLStack.h"
using namespace std;
//gets the number of the stack
int LLStack::getNum()
{
	return num;
}
//constructor
LLStack::LLStack() {
	head = NULL;
	num = NULL;
}
//destructor
LLStack::~LLStack() {
	delete head;
}
//pushes the given item to the stack
void LLStack::PUSH(int s) {

	head = new StackNode(s, head);
}
//performs a pop on th stack returning the item
int LLStack::POP() {
		StackNode* h = head;
		head = h->getnext();
		h->setnext(NULL);
		int s = h->getS();
		delete h;
		return s;
}
//returs bool telling you if stack is empty
bool LLStack::ISEMPTY() {

	return !head;
}

//constructor
LLStack::LLStack(int newNum) {
	head = NULL;
	num = newNum;
}
