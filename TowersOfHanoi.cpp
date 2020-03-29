//Jared VanEnkevort
#include <iostream>
#include <string>
#include "LLStack.h"
#include "TowersOfHanoi.h"
using namespace std;

int main(int argc, char* argv[]) {
	// below we take in how many disks the user wants sorted, then push them all to the 1st "pole".
	int disks;
	LLStack src = LLStack("src");
	LLStack dest = LLStack("dest");
	LLStack aux = LLStack("aux");
	cout << "Enter the amount of disks:\n";
	cin >> disks;
	for (int i = disks; i > 0; i--) {
		src.PUSH(i);
		cout << "pushing disk " << i << " to first stack\n";
	}
	// I'm casting moves as an int to get rid of a type conversion warning
	int moves = (int)pow(2, disks) - 1;
	cout << "Number of moves " << moves << "\n";
	if (moves % 2 == 0) {
		LLStack temp = dest;
		dest = aux;
		aux = temp;
	}
	//depending on what iteration of moves we are on, move disks from and to specific poles
	for (int i = 1; i <= moves; i++) {
		if (i % 3 == 1) {
			makeValidMove(src, dest);
		}
		else if (i % 3 == 2) {
			makeValidMove(src, aux);
		}
		else if (i % 3 == 0) {
			makeValidMove(aux, dest);

		}

	}

}
//decides how to move disk while adhering to the rules of the game
void makeValidMove(LLStack stack1, LLStack stack2) {
	int topNode1 = stack1.POP();
	int topNode2 = stack2.POP();
	//handling the first stack being empty
	if (topNode1 == -10) {
		stack1.PUSH(stack2.POP());
		printMove(stack2.getName(), stack1.getName(), topNode2);
	}
	//handling the second stack being empty
	else if (topNode2 == -10) {
		stack2.PUSH(stack1.POP());
		printMove(stack1.getName(), stack2.getName(), topNode1);
	}
	//handling stack1's disk being greater than stack 2's
	else if (topNode1 > topNode2) {
		stack1.PUSH(topNode1);
		stack1.PUSH(topNode2);
		printMove(stack2.getName(), stack1.getName(), topNode2);
	}
	//handling stack2's disk being greater than stack 1's
	else {
		stack2.PUSH(topNode2);
		stack2.PUSH(topNode1);
		printMove(stack1.getName(), stack2.getName(), topNode1);
	}

}

void printMove(string src, string dest, int diskNum) {
	cout << "moved disk " << diskNum << " from " << src << " to " << dest << "\n";
}