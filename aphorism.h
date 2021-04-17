#ifndef  APHORISM_H
#define APHORISM_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {

	struct aphorism {	
		string author;
	};

	aphorism* Aphorism_Input(ifstream& ifst);
	void Aphorism_Output(struct aphorism* aphorism, ofstream& ofst);
} // end type_phrases namespace
#endif // APHORISM_H