//Daniel Bevilacqua
//02/03/2017
#include<iostream>
#include<cstdlib>
#include"Hang.cpp"
using namespace std;

int main() {
	hangLogic hanged;
	hanged.intro();
	bool play = true;
	int correct = -2;
	int imgNum = 6;
	hanged.letterGuess();
	do {
		correct = hanged.match();

		play = hanged.keepPlaying();
		if (correct == -1) {
			exit(EXIT_SUCCESS);
		}
		else {
			hanged.letterGuess();
		}
	} while (play != false);
}
