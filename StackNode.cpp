//Jared VanEnkevort
#include <iostream>
#include <string>
#include <cstdlib>
#include "StackNode.h"
using namespace std;

StackNode::StackNode(int s, StackNode* n) {

	S = s;
	next = n;
}

StackNode::~StackNode() {

	delete next;
}

int StackNode::getS() {

	return S;
}

StackNode* StackNode::getnext() {

	return next;
}

void StackNode::setnext(StackNode* n) {

	next = n;
}