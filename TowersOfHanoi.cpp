//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	int disk1Loc = -1;
	int direction = 0;
	LLStack *poles = new LLStack[3];
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
		disk1Loc = 1;
		direction = 1;
	}
	else{
		makeValidMove(poles[0],poles[2]);
		disk1Loc = 2;
		direction = -1;
	}
	cout << poles;
	//depending on what iteration of moves we are on, move disks from and to specific poles
	int moveCt = 2;
	while (poles[0].ISEMPTY() != true &&!poles[1].ISEMPTY()!= true) {
		//if move is even make any move not involving disk 1
		if (moveCt % 2 == 0) {
			vector <int> choices;
			for (int i = 0; i < 2; i++) {
				if (i != disk1Loc) {
					choices.push_back(i);			
				}
			}
			int choice1 = choices.at(0);
			int choice2 = choices.at(1);
			if (poles[choice1].ISEMPTY()) {
				makeValidMove(poles[choice2],poles[choice1] );
			}
			else if (poles[choice2].ISEMPTY()) {
				makeValidMove(poles[choice1], poles[choice2]);

			}
			else{
				int choice1Num = poles[choice1].POP();
				int choice2Num = poles[choice2].POP();
				poles[choice1].PUSH(choice1Num);
				poles[choice2].PUSH(choice2Num);
				if (choice1Num > choice2Num) {
					makeValidMove(poles[choice2], poles[choice1]);
				}
				else {
					makeValidMove(poles[choice1], poles[choice2]);

				}


			}
		}
		//if move # is odd
		else {
			if (direction == -1) {
				//move disk left
				if (disk1Loc == 0) {
					makeValidMove(poles[disk1Loc], poles[2]);
					disk1Loc = 2;
				}else{
					makeValidMove(poles[disk1Loc], poles[disk1Loc - 1]);
					disk1Loc = disk1Loc - 1;
				}
			}
			else {
				//move disk right
				if (disk1Loc == 2) {
					makeValidMove(poles[disk1Loc], poles[0]);
					disk1Loc = 0;
				}else{
					makeValidMove(poles[disk1Loc], poles[disk1Loc + 1]);
					disk1Loc = disk1Loc + 1;
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