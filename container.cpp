#include <iostream>
#include <fstream>
#include "container.h"
#include "node.h"

namespace type_phrases {

	void Container_Init(container* list) {
		list->size = 0;
		list->head = NULL;
		list->tail = NULL;
	}

	void Container_Clear(struct container* list) {
		if (list->head == NULL) {
			cout << "|Container cleanup failed. It's empty|" << endl;
			return;
		}
		else {
			node* currentNode;
			for (int i = 0; i < list->size; i++) {
				currentNode = list->tail;
				list->tail = list->tail->prev;
				free(currentNode);
			}
			list->head = NULL;
			list->tail = NULL;
			list->size = 0;
		}
	}

	void Container_Fill(struct container* list, ifstream& ifst) {
		if (list->head != NULL) {
			cout << "|Ñontainer filling failed. It's not empty|" << endl;
			return;
		}
		while (!ifst.eof()) {
			if (Node_Add(list, ifst)) {
				(list->size)++;
			}
			else {
				cout << "|Addition node #" << (list->size + 1) <<" failed|" << endl;
			}
		}
	}

	void Container_Output(struct container* list, ofstream& ofst) {
		if (list->size == 0) {
			cout << "|Container output failed. It's empty|" << endl;
			return;
		}
		ofst << "Container contains " << list->size << " elements." << endl;
		cout << "|Container contains " << list->size << " elements|" << endl;

		for (int i = 0; i < list->size; i++) {
			if (!Node_Output(list->head, i, ofst)) {
				cout << "|Error in node #" << i << " output|" << endl;
			}
		}
	}
}