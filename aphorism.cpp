#include <iostream>
#include <fstream>
#include "aphorism.h"

namespace type_phrases {

	aphorism* aphorism_Input(ifstream& ifst) {
		aphorism* newObj = new aphorism();
		getline(ifst, newObj->author);
		return newObj;
	}

	void aphorism_Output(struct aphorism* aphorism, ofstream& ofst) {
		ofst << "Author's name: " << aphorism->author << ";" << endl;
	}
}