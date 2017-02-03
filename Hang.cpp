//Daniel Bevilacqua
//02/03/2017
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class hangLogic {
public:
	void hangingMan(int pick) {
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 10);
		if (pick == 6) {
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |       " << endl;
			std::cout << " |       " << endl;
			std::cout << " |       " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
		if (pick == 5) {
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |    O  " << endl;
			std::cout << " |       " << endl;
			std::cout << " |       " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
		if (pick == 4) {
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   _O_ " << endl;
			std::cout << " |       " << endl;
			std::cout << " |       " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
		if (pick == 3) {
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   _O_ " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |       " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
		if (pick == 2) {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   _O_ " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   /   " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
		if (pick == 1) {
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "  ____   " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   _O_ " << endl;
			std::cout << " |    |  " << endl;
			std::cout << " |   / \\ " << endl;
			std::cout << "_|___    " << endl;
			std::cout << endl;
			exit;
		}
	}

	void intro() {
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 6; i > imgAn; --i) {
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Welcome to HangMan! V1.0, I hope your ready to play.\n";
			hangingMan(i);
			Sleep(1000);
			system("CLS");
		}
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Welcome to HangMan! V1.0, I hope your ready to play.\n";
		std::cout << "Please enter the word of choosing: ";
		std::cin >> hangWord;
		permHangWord = hangWord;
		std::cout << "\n";
		system("CLS");
		std::cout << "Welcome to HangMan! V1.0, I hope your ready to play.\n";
	}

	void letterGuess() {
		if (STOP == -1) {
			std::cout << "Enter your guessed letter: ";
			std::cin >> guess;
		}
		else
			exit;
	}

	int match() {
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 10);
		flip = 1;
		int leng = hangWord.length();
		int gmeOvrCntr = leng;
		for (int i = 0; i < leng; ++i) {
			if (guess == hangWord[i]) {
				system("CLS");
				std::cout << "We have a match!\nThe match was " << guess << "\n";
				hangingMan(hangImg + 1);
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << "You have " << hangImg << " guesses left.\n";
				hangWord[i] = 0;
				flip = 0;
				if (hangWord[i + 1] != 0) {
					return 0;
				}
			}
			if (hangWord[i] == 0) {
				--gmeOvrCntr;
				if (gmeOvrCntr < 1) {
					std::cout << "You win!!!\n";
					std::cout << "The winning word was: " << permHangWord << "\n\n";
					return -1;
				}
			}
		}
		if (flip != 0) {
			system("CLS");
			std::cout << "The letter " << guess << " is not in the word. \n\n";
			hangingMan(hangImg);
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "You have " << hangImg - 1 << " guesses left.\n";
			if (hangImg - 1 == 0) {
				std::cout << "The winning word was: " << permHangWord << "\n";
				return -1;
			}
			--hangImg;
			return 0;
		}
		return 0;
	}

	bool keepPlaying() {
		if (hangImg > 0) {
			return true;
		}
		else return false;
	}

private:
	string permHangWord;
	string hangWord;
	int imgAn = 0;
	char guess;
	int hangImg = 6;
	int flip = 1;
	char playAgain;
	int STOP = -1;
};