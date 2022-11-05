#include "iostream";
#include "fstream";
#include "string";
#include "Windows.h" // Windows API for console output and copy-paste feature.
#include "Generator.h" // Password Generator main generation functions of the password.
#include "consoleapi2.h"
// DMHDev's C++ Password Generator v1.0
// Written on C++; Uses default C++ randomizing algorithms. Probably usable, but mainly created for personal usage and for fun and C++ practicing.
// Licensed under MIT License.

// Use external Windows API callback to copy password into clipboard memory.
void toClipboard(HWND hwnd, const std::string& s) {
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

void main() {
	// Password Generator Command Line Interface (PG CLI Main Menu)
	SetConsoleOutputCP(8859);

	SetConsoleTitleA("DMHDev's Random Password Generator CLI v1.0");

	// User Input
	int mode{};
	int length{};

	// Main Menu Entries:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	std::cout << "------------------------------------------\n";
	std::cout << " DMHDev's Random Password Generator v1.0\n";
	std::cout << "------------------------------------------\n\n";

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "  Description: You can generate your password of any length and strength you wish.\n  Uses lots of randomization and encryption methods to make it much harder to bruteforce or decrypt \n  if service uses hashing and salting methods to store passwords.";
	std::cout << "\n";

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\nChoose preffered security strength level of your future password:\n \n";

	std::cout << " 1 - Low strength, use only numbers.\n";
	std::cout << " 2 - Low strength, previous mode + English letters.\n";
	std::cout << " 3 - Medium strength, previous mode + non-standard sentence symbols such as !, #, $, %, ^, &, *.\n";
	std::cout << " 4 - Medium strength, previous mode + non-standard math symbols and syntax symbols such as (, ), [, ], +, ,, -, ., /.\n";
	std::cout << " 5 - Medium-High strength, previous mode + logic and comparison symbols such as :, ;, <, =, >, ?, @.\n";
	std::cout << " 6 - High strength, previous mode + Cyrillic symbols.\n";
	std::cout << " 7 - High strength, previous mode + rightest ASCII symbols. (Requires specific console encoding!)\n";
	std::cout << " 8 - Very high strength, previous mode + use ASCII C++ console borders symbols. (Requires specific console encoding!)\n";
	std::cout << " 9 - Highest strength, previous mode + use Unicode symbols. (Some applications or websites cannot recognize some symbols from this algorithm, use at your own risk!)\n";
	std::cout << "\n";

	std::cout << "Choose password strength generation level: ";
	std::cin >> mode;
	while (true) {
		if (mode <= 9 && mode > 0) break;
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "\nError: Invalid security strength level. Please, use correct mode type!\n";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Choose password strength generation level: ";
		std::cin >> mode;
		std::cout << "\n";
	}

	std::cout << "Successfully selected mode " + std::to_string(mode) + ".";
	std::cout << "\n";

	std::cout << "Choose password length: ";
	std::cin >> length;
	std::cout << "\n";

	while (true) {
		if (length > 0 && length < MAXINT) break;
		SetConsoleTextAttribute(hConsole, 12);
		if (length == 0) std::cout << "\nError: Length cannot be zero. Please, type any length higher than 0!\n";
		if (length < 0) std::cout << "\nError: Length cannot be negative. Please, type any positive length!\n";
		if (length >= MAXINT) { std::cout << "\nError: Length cannot be more than Integer limit. Please, type any length lesser than " + std::to_string(MAXINT) + "!\n"; length = 0; }
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Choose password length: ";
		std::cin >> length;
	}

	SetConsoleTextAttribute(hConsole, 4);
	std::string password = generate(mode, length);
	std::cout << "Generated password: " + password + " \n";
	HWND hwnd = GetDesktopWindow(); // Get current generator window
	toClipboard(hwnd, password);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Your password has been copied into your clipboard!";
	std::cout << "\n";

	SetConsoleTextAttribute(hConsole, 15); // Bring back default console;
	SetConsoleOutputCP(65001);
	system("pause");
}