#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {
	// ввод параметров загадки из файла
	riddle* riddle_Input(ifstream& ifst) {
		riddle* newObj = new riddle();
		getline(ifst, newObj->answer);
		return newObj;
	}
	// вывод параметров загадки в форматируемый поток
	void riddle_Output(struct riddle* riddle, ofstream& ofst) {
		ofst << "Answer: " << riddle->answer << ";" << endl;
	}
}