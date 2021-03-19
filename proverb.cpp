#include <iostream>
#include <fstream>
#include "proverb.h"

namespace type_phrases {
	proverb* proverb_Input(ifstream& ifst) {
		proverb* newObj = new proverb();
		getline(ifst, newObj->country);
		return newObj;
	}

	void proverb_Output(struct proverb* proverb, ofstream& ofst) {
		ofst << "Ñountry: " << proverb->country << ";" << endl;
	}
}