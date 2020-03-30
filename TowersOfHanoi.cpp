//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
using namespace std;

int main(int argc, char* argv[]) {
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	LLStack *poles[3];
	for (int i = 0; i < 3; i++) {
		poles[i] =  new LLStack();
	}
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	for (int i = disks; i > 0; i--) {
		poles[0]->PUSH(i);
		cout << "pushing disk " << i << " to first stack\n";
	}
	// I'm casting moves as an int to get rid of a type conversion warning
	int moves = (int)pow(2, disks) - 1;
	cout << "Number of moves " << moves << "\n";
	if (moves % 2 == 0) {

	}
	//depending on what iteration of moves we are on, move disks from and to specific poles
	for (int i = 1; i <= moves; i++) {


	}

}
//decides how to move disk while adhering to the rules of the game
void makeValidMove(LLStack stack1, LLStack stack2) {
	

}

void printMove(string src, string dest, int diskNum) {
	cout << "moved disk " << diskNum << " from " << src << " to " << dest << "\n";
}