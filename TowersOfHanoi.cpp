//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
using namespace std;

int main(int argc, char* argv[]){
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	LLStack A = LLStack();
	LLStack B = LLStack();
	LLStack C = LLStack();	
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	for (int i = disks; i > 0; i--) {
		A.PUSH(i);
		cout << "pushing disk " << i << " to stack A\n";
	}
	int moves = pow(2, disks)-1;
	cout << "Number of moves " << moves << "\n";
	if (moves % 2 == 0) {

	}
	else {

	}
	
}
void hanoi(LLStack src, LLStack dest, LLStack outer, int disks) {

	if (disks % 2 == 0) {
		LLStack temp(dest);

	}
}
//decides how to move disk while adhering to the constraints of the problem
void makeValidMove(int pole1, int pole2){
	return;
}

void moveDisk(LLStack src, LLStack dest){
	


}
