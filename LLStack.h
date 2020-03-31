//Jared VanEnkevort
//contains the prototypes for all functions present in LLStack.cpp
#ifndef _LLSTACK_
#define _LLSTACK_

#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
using namespace std;

class StackNode;
class LLStack {
private:
	int num;
	StackNode* head;
public:
	int getNum();
	LLStack();
	LLStack(int newNum);
	~LLStack();
	void PUSH(int s);
	int POP();
	bool ISEMPTY();
};


#endif