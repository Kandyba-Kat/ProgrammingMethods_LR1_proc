#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {
	// ���� ���������� ������� �� �����
	riddle* riddle_Input(ifstream& ifst) {
		riddle* newObj = new riddle();
		getline(ifst, newObj->answer);
		return newObj;
	}
	// ����� ���������� ������� � ������������� �����
	void riddle_Output(struct riddle* riddle, ofstream& ofst) {
		ofst << "Answer: " << riddle->answer << ";" << endl;
	}
}