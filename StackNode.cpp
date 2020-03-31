//Jared VanEnkevort
//contains the function definitions for the prototypes present in StackNode.h
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
using namespace std;
//constuctor
StackNode::StackNode(int s, StackNode* n) {

	S = s;
	next = n;
}
//destructor
StackNode::~StackNode() {

	delete next;
}
//gets a node's int
int StackNode::getS() {

	return S;
}
//gets a pointer to the next node
StackNode* StackNode::getnext() {

	return next;
}
//sets this nodes next
void StackNode::setnext(StackNode* n) {

	next = n;
}