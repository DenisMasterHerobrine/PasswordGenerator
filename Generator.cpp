#define _CRT_SECURE_NO_WARNINGS

#include "chrono"
#include "string"
#include "ctime"
#include "iomanip"
#include "Generator.h"
#include "stdlib.h"
#include "regex"
#include "iostream"
#include "algorithm"

unsigned int getSeed()
{
	// A Pseudo-Random based on Memory and Time Salting Method

	int* arr[1]{0};

	int* abstractMemorySalt = new int{};
	std::string currentTimeSalt = std::to_string(time(0));
	std::string abstractMemorySaltString{};

	srand(time(0));

	for (int i = 1; i < rand() % 25; i++) {
		abstractMemorySaltString += std::to_string(abstractMemorySalt[i]); // Ignore the warning, we need total randomness!
	}

	std::replace(abstractMemorySaltString.begin(), abstractMemorySaltString.end(), '-', '5');

	std::string seed = currentTimeSalt + abstractMemorySaltString;
	std::string prepSeed{};
	int intSeed{};
	for (int j = 0; j < 9; j++) {
		prepSeed += seed[rand() % seed.size()];
	}
	intSeed = std::stoi(prepSeed);

	unsigned int saltedRandom = intSeed;

	return saltedRandom;
}

std::string generate(int mode, int length)
{
	std::string password{};
	switch (mode) {
	case 1: {
		static const char layer1[] = "0123456789";
		srand(getSeed());
		for (int i = 0; i < length; i++) {
			password += layer1[rand() % 10];
		}
		break;
	}
	case 2: {
		static const char layer2[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		srand(getSeed());
		size_t size = sizeof(layer2) / sizeof(layer2[0]);
		for (int i = 0; i < length; i++) {
			password += layer2[rand() % size];
		}
		break;
	}

	case 3: {
		static const char layer3[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*";
		srand(getSeed());
		size_t size = sizeof(layer3) / sizeof(layer3[0]);
		for (int i = 0; i < length; i++) {
			password += layer3[rand() % size];
		}
		break;
	}

	case 4: {
		static const char layer4[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./";
		srand(getSeed());
		size_t size = sizeof(layer4) / sizeof(layer4[0]);
		for (int i = 0; i < length; i++) {
			password += layer4[rand() % size];
		}
		break;
	}

	case 5: {
		static const char layer5[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./:;<>=?";
		srand(getSeed());
		size_t size = sizeof(layer5) / sizeof(layer5[0]);
		for (int i = 0; i < length; i++) {
			password += layer5[rand() % size];
		}
		break;
	}

	case 6: {
		static const char layer6[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./:;<>=?абвгдеёжзийклмнопрстуфхцчшъыьэюяАБВГДЕЁЖЗИЙКЛМАОПРСТУФХЦЧШЪЫЬЭЮЯ";
		srand(getSeed());
		size_t size = sizeof(layer6) / sizeof(layer6[0]);
		for (int i = 0; i < length; i++) {
			password += layer6[rand() % size];
		}
		break;
	}

	case 7: {
		static const char layer7[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./:;<>=?абвгдеёжзийклмнопрстуфхцчшъыьэюяАБВГДЕЁЖЗИЙКЛМАОПРСТУФХЦЧШЪЫЬЭЮЯЄєЇїЎў°··√№¤■";
		srand(getSeed());
		size_t size = sizeof(layer7) / sizeof(layer7[0]);
		for (int i = 0; i < length; i++) {
			password += layer7[rand() % size];
		}
		break;
	}

	case 8: {
		static const char layer8[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./:;<>=?абвгдеёжзийклмнопрстуфхцчшъыьэюяАБВГДЕЁЖЗИЙКЛМАОПРСТУФХЦЧШЪЫЬЭЮЯЄєЇїЎў°··√№¤■░▒▓││┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀";
		srand(getSeed());
		size_t size = sizeof(layer8) / sizeof(layer8[0]);
		for (int i = 0; i < length; i++) {
			password += layer8[rand() % size];
		}
		break;
	}

	case 9: {
		static const char layer8[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]+,-./:;<>=?абвгдеёжзийклмнопрстуфхцчшъыьэюяАБВГДЕЁЖЗИЙКЛМАОПРСТУФХЦЧШЪЫЬЭЮЯЄєЇїЎў°··√№¤■░▒▓││┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§↨↑↓→←∟↔▲▼";
		srand(getSeed());
		size_t size = sizeof(layer8) / sizeof(layer8[0]);
		for (int i = 0; i < length; i++) {
			password += layer8[rand() % size];
		}
		break;
	}

	}

	return password;
}
