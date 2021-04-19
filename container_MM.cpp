#include <iostream>
#include <fstream>
#include "container.h"
#include "node.h"
#include "phrase.h"

namespace type_phrases {
	bool Node_Output(struct node* headNode, int pos, ofstream& ofst); // сигнатура

	void MultiMethod(struct container* list, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		node* currentNode1;
		node* currentNode2;
		for (int i = 0; i < list->size - 1; i++) {
			currentNode1 = list->head;
			for (int p = 0; p < i; p++) {
				currentNode1 = currentNode1->next;
			}
			currentNode2 = currentNode1->next;
			for (int j = i + 1; j < list->size; j++) {
				switch (currentNode1->info->key) {
				case phrase::type::APHORISM:					
					switch (currentNode2->info->key) {
					case phrase::type::APHORISM:
						ofst << "\tAphorism and Aphorism." << endl;
						break;
					case phrase::type::PROVERB:
						ofst << "\tAphorism and Proverb." << endl;
						break;
					case phrase::type::RIDDLE:
						ofst << "\tAphorism and Riddle." << endl;
						break;
					default:
						ofst << "\tAphorism and Unknown type." << endl;
						break;
					}
					currentNode2 = currentNode2->next;
					break;
				case phrase::type::PROVERB:
					switch (currentNode2->info->key) {
					case phrase::type::APHORISM:
						ofst << "\tProverb and Aphorism." << endl;
						break;
					case phrase::type::PROVERB:
						ofst << "\tProverb and Proverb." << endl;
						break;
					case phrase::type::RIDDLE:
						ofst << "\tProverb and Riddle." << endl;
						break;
					default:
						ofst << "\tProverb and Unknown type." << endl;
						break;
					}
					currentNode2 = currentNode2->next;
					break;
				case phrase::type::RIDDLE:
					switch (currentNode2->info->key) {
					case phrase::type::APHORISM:
						ofst << "\tRiddle and Aphorism." << endl;
						break;
					case phrase::type::PROVERB:
						ofst << "\tRiddle and Proverb." << endl;
						break;
					case phrase::type::RIDDLE:
						ofst << "\tRiddle and Riddle." << endl;
						break;
					default:
						ofst << "\tRiddle and Unknown type." << endl;
						break;
					}
					currentNode2 = currentNode2->next;
					break;
				default:
					ofst << "Unknown type." << endl;
					break;
				}

				Node_Output(list->head, i, ofst);
				Node_Output(list->head, j, ofst);

			}
		}
	}
}

