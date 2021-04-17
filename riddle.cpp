#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {
	// ���������
	string Check_In_String(ifstream& ifst);

	// ���� ���������� ������� �� �����
	riddle* Riddle_Input(ifstream& ifst) {
		riddle* newObj = new riddle();
		if ((newObj->answer = Check_In_String(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}
	// ����� ���������� ������� � ������������� �����
	void Riddle_Output(struct riddle* riddle, ofstream& ofst) {
		ofst << "Answer: " << riddle->answer << ";" << endl;
	}
}