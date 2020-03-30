//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
using namespace std;

int main(int argc, char* argv[]) {
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	int disk1Loc = -1;
	int direction = 0;
	LLStack poles[3];
	for (int i = 0; i < 3; i++) {
		poles[i] = LLStack(i+1);
	}
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	for (int i = disks; i > 0; i--) {
		poles[0].PUSH(i);
		cout << "pushing disk " << i << " to first stack\n";
	}
	// I'm casting moves as an int to get rid of a type conversion warning
	int moves = (int)pow(2, disks) - 1;
	cout << "Number of moves " << moves << "\n";
	if (disks % 2 == 0) {
		makeValidMove(poles[0],poles[1]);
		int disk1Loc = 1;
		int direction = 1;
	}
	else{
		makeValidMove(poles[0],poles[2]);
		int disk1Loc = 2;
		int direction = -1;
	}
	//depending on what iteration of moves we are on, move disks from and to specific poles
	int moveCt = 2;
	while (!poles[0].ISEMPTY()&& !poles[1].ISEMPTY()) {
		if (moveCt % 2 == 0) {
			

		}
		//if move # is odd
		else {
			if (direction == -1) {
				//move disk left
				if (disk1Loc == 0) {
					makeValidMove(poles[disk1Loc], poles[2]);
					disk1Loc = 2;
				}
				else {
					makeValidMove(poles[disk1Loc], poles[disk1Loc - 1]);
					disk1Loc = disk1Loc - 1;
				}
			}
			else {
				//move disk right
				if (disk1Loc == 2) {
					makeValidMove(poles[disk1Loc], poles[0]);
					disk1Loc = 0;
				}
			}
		}

		moveCt++;
	}

}
//moves disk from one pole to another
void makeValidMove(LLStack from, LLStack to) {
	int disk = from.POP();
	to.PUSH(disk);
	printMove(from.getNum(), to.getNum(), disk);
}
//prints a move made from one pole to another
void printMove(int from, int to, int diskNum) {
	cout << "moved disk " << diskNum << " from pole " << from << " to pole " << to << "\n";
}