#ifndef  PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_phrases {
	// структура, обощающа€ все имеющиес€ изречени€
	struct phrase {
		enum type { APHORISM, PROVERB, RIDDLE };
		type key;
		string content;
		short eval;
		void* phrase;
	};

	string Check_In_String(ifstream& ifst);
	phrase* Phrase_Input(ifstream& ifst);
	bool Phrase_Output(struct phrase* phrase, ofstream& ofst);
} // end type_phrases namespace
#endif // PHRASE_H