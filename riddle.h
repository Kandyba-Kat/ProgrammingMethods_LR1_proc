#ifndef  RIDDLE_H
#define RIDDLE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// �������
	struct riddle {
		string answer; // �����
	};

	riddle* Riddle_Input(ifstream& ifst);
	void Riddle_Output(struct riddle* riddle, ofstream& ofst);
} // end type_phrases namespace
#endif // RIDDLE_H