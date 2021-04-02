#include <iostream>
#include <fstream>
#include "phrase.h"

namespace type_phrases {

	phrase* phrase_Input(ifstream& ifst) {
		phrase* newObj;
		string ev;
		string k;
		getline(ifst, k);
		switch (atoi(k.c_str()))
		{
		case 1:
			newObj = new phrase;
			newObj->phrase = aphorism_Input(ifst);
			getline(ifst, newObj->content);
			getline(ifst, ev);
			newObj->eval = stoi(ev);
			newObj->key = phrase::type::APHORISM;
			break;
		case 2:
			newObj = new phrase;
			newObj->phrase = proverb_Input(ifst);
			getline(ifst, newObj->content);
			getline(ifst, ev);
			newObj->eval = stoi(ev);
			newObj->key = phrase::type::PROVERB;
			break;
		case 3:
			newObj = new phrase;
			newObj->phrase = riddle_Input(ifst);
			getline(ifst, newObj->content);
			getline(ifst, ev);
			newObj->eval = stoi(ev);
			newObj->key = phrase::type::RIDDLE;
			break;
		default:
			cout << "There are no such type of phrases!" << endl;
			return 0;
		}
		return newObj;
	}

	bool phrase_Output(struct phrase* phrase, ofstream& ofst) {
		if (phrase->key == phrase::type::APHORISM) {
			aphorism_Output((aphorism*)phrase->phrase, ofst);
			ofst << "Aphorism: " << phrase->content << ";\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else if (phrase->key == phrase::type::PROVERB) {
			proverb_Output((proverb*)phrase->phrase, ofst);
			ofst << "Proverb: " << phrase->content << ";\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else if (phrase->key == phrase::type::RIDDLE) {
			riddle_Output((riddle*)phrase->phrase, ofst);
			ofst << "Riddle: " << phrase->content << ";\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else {
			ofst << "Incorrect phrase!" << endl;
			return false;
		}
	}
}