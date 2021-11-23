#pragma once
// HEADER
#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Word {

public:
	string word = " ";
	string hint = " ";

	Word() {
		this->word = " ";
		this->hint = " ";
	}
	Word(string word, string hint) {
		this->word = word;
		this->hint = hint;
	}
};

