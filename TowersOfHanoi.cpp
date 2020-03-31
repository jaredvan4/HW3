//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
#include <vector>
using namespace std;
LLStack poles [3];
int main(int argc, char* argv[]) {
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	int disk1Loc = -1;
	int direction = 0;
	
	//LLStack* poles = new LLStack[3];
	for (int i = 0; i < 3; i++) {
		poles[i] = LLStack(i + 1);
	}
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	if (disks == 0) {
		cout << "no disks to move, done!\n";
		exit(0);
	}
	for (int i = disks; i > 0; i--) {
		poles[0].PUSH(i);
		cout << "pushing disk " << i << " to stack 1\n";
	}
	// I'm casting moves as an int to get rid of a type conversion warning
	int moves = (int)pow(2, disks) - 1;
	if (disks % 2 == 0) {
		makeValidMove(0, 1);
		disk1Loc = 1;
		direction = 1;
	}
	else {
		makeValidMove(0,2);
		disk1Loc = 2;
		direction = -1;
	}
	//depending on what iteration of moves we are on, move disks from and to specific poles
	int moveCt = 2;
	while (true) {
		if (poles[0].ISEMPTY() && poles[1].ISEMPTY()) {
			break;
		}
		//if move is even make any move not involving disk 1
		if (moveCt % 2 == 0) {
			vector <int> choices;
			for (int i = 0; i < 3; ++i) {
				if (i != disk1Loc) {
					choices.push_back(i);
				}
			}
			int choice1 = choices[0];
			int choice2 = choices[1];
			//check if either stack is empty
			if (poles[choice1].ISEMPTY()) {
				makeValidMove(choice2,choice1);
			}
			else if (poles[choice2].ISEMPTY()) {
				makeValidMove(choice1, choice2);

			}
			else {
				//check which stack has the larger disk
				int choice1Num = poles[choice1].POP();
				int choice2Num = poles[choice2].POP();
				poles[choice1].PUSH(choice1Num);
				poles[choice2].PUSH(choice2Num);
				if (choice1Num > choice2Num) {
					makeValidMove(choice2, choice1);
				}
				else {
					makeValidMove(choice1, choice2);

				}


			}
		}
		//if move # is odd
		else {
			if (direction == -1) {
				//move disk left
				if (disk1Loc == 0) {
					makeValidMove(disk1Loc, 2);
					disk1Loc = 2;
				}
				else {
					makeValidMove(disk1Loc, disk1Loc - 1);
					disk1Loc = disk1Loc - 1;
				}
			}
			else {
				//move disk right
				if (disk1Loc == 2) {
					makeValidMove(disk1Loc, 0);
					disk1Loc = 0;
				}
				else {
					makeValidMove(disk1Loc, disk1Loc + 1);
					disk1Loc = disk1Loc + 1;
				}
			}
		}

		moveCt++;
	}
	cout << "Done!\n";
}
//moves disk from one pole to another
void makeValidMove(int from, int to) {
	int disk = poles[from].POP();
	poles[to].PUSH(disk);
	printMove(poles[from].getNum(), poles[to].getNum(), disk);
}
//prints a move made from one pole to another
void printMove(int from, int to, int diskNum) {
	cout << "moved disk " << diskNum << " from pole " << from << " to pole " << to << "\n";
}