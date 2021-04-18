#include <iostream>
#include <fstream>
#include "container.h"
#include "node.h"
#include "phrase.h"

namespace type_phrases {
	bool node_Output(struct node* headNode, int pos, ofstream& ofst); // сигнатура

	void MultiMethod(struct container* list, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		node* currentNode1;
		node* currentNode2;
		for (int i = 0; i < list->size - 1; i++) {
			for (int j = i + 1; j < list->size; j++) {
				currentNode1 = list->head;
				for (int p = 0; p < i; p++) {
					currentNode1 = currentNode1->next;
				}
				switch (currentNode1->info->key) {
				case phrase::type::APHORISM:
					currentNode2 = currentNode1->next;
					switch (currentNode2->info->key) {
					case phrase::type::APHORISM:
						ofst << "Aphorism and Aphorism." << endl;
						break;
					case phrase::type::PROVERB:
						ofst << "Aphorism and Proverb." << endl;
						break;
					default:
						ofst << "Aphorism and Unknown type." << endl;
						break;
					}
					break;
				case phrase::type::PROVERB:
					currentNode2 = currentNode1->next;
					switch (currentNode2->info->key) {
					case phrase::type::APHORISM:
						ofst << "Proverb and Aphorism." << endl;
						break;
					case phrase::type::PROVERB:
						ofst << "Proverb and Proverb." << endl;
						break;
					default:
						ofst << "Proverb and Unknown type." << endl;
						break;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
					break;
				}

				node_Output(list->head, i, ofst);
				node_Output(list->head, j, ofst);

			}
		}
	}
}

