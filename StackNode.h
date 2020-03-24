//Jared VanEnkevort
#ifndef _STACKNODE_
#define _STACKNODE_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class StackNode {
private:
	int S;
	StackNode* next;
public:
	StackNode(int s, StackNode* n);
	~StackNode();
	int getS();
	StackNode* getnext();
	void setnext(StackNode* n);
};


#endif
