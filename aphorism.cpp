#include <iostream>
#include <fstream>
#include "aphorism.h"

namespace type_phrases {
	// сигнатура
	string Check_In_String(ifstream& ifst);

	aphorism* Aphorism_Input(ifstream& ifst) {
		aphorism* newObj = new aphorism();
		if ((newObj->author = Check_In_String(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}

	void Aphorism_Output(struct aphorism* aphorism, ofstream& ofst) {
		ofst << "Author's name: " << aphorism->author << ";" << endl;
	}
}