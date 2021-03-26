#ifndef  PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
#include "aphorism.h"
#include "proverb.h"
using namespace std;

namespace type_phrases {
	// ���������, ��������� ��� ��������� ���������
	struct phrase {
		enum type { APHORISM, PROVERB };
		type key;
		string content;
		int eval;
		void* phrase;
	};

	phrase* phrase_Input(ifstream& ifst);
	bool phrase_Output(struct phrase* phrase, ofstream& ofst);
} // end type_phrases namespace
#endif // PHRASE_H

