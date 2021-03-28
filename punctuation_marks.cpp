#include "phrase.h"

namespace type_phrases {
	int num_punct_marks(struct phrase* phrase) {
		string punctM = ".,;:\"!?()-";
		int cnt = 0;
		for (unsigned i = 0; i < phrase->content.length(); i++) {
			for (unsigned j = 0; j < punctM.length(); j++) {
				if (phrase->content[i] == punctM[j]) {
					cnt++;
				}
			}
		}
		return cnt;
	}
}