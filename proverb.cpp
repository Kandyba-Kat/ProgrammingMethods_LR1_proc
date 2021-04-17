#include <iostream>
#include <fstream>
#include "proverb.h"

namespace type_phrases {
	// ñèãíàòóðà
	string Check_In_String(ifstream& ifst);

	proverb* Proverb_Input(ifstream& ifst) {
		proverb* newObj = new proverb();
		if ((newObj->country = Check_In_String(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}

	void Proverb_Output(struct proverb* proverb, ofstream& ofst) {
		ofst << "Ñountry: " << proverb->country << ";" << endl;
	}
}