//Jared VanEnkevort
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
	string name;
	StackNode* head;
public:
	string getName();
	LLStack(string name);
	~LLStack();
	void PUSH(int s);
	int POP();
	bool ISEMPTY();
};


#endif