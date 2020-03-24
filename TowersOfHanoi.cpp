//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
using namespace std;

int main(int argc, char* argv[]){
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	LLStack source = LLStack();
	LLStack pole2 = LLStack();
	LLStack pole3 = LLStack();	
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	for (int i = disks; i > 0; i--) {
		source.PUSH(i);
		cout << "pushing disk " << i << " to stack 1\n";
	}
	int moves = pow(2, disks)-1;
	cout << "Number of moves " << moves << "\n";
	
}
void hanoi(LLStack src, LLStack dest, LLStack outer, int disks) {

	if (disks % 2 == 0) {
		LLStack temp(dest);

	}
}

void moveDisk(LLStack src, LLStack dest){
	


}
