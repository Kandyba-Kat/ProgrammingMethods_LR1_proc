#include <iostream>
#include <fstream>
#include "container.h"
#include "node.h"

namespace type_phrases {
	void container_Init(container* list) {
		list->size = 0;
		list->head = NULL;
		list->tail = NULL;
	}

	void container_Clear(struct container* list) {
		if (list->head == NULL) return;
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

	void container_Fill(struct container* list, ifstream& ifst) {
		while (!ifst.eof()) {
			if (node_Add(list, ifst)) {
				(list->size)++;
			}
		}
	}

	void container_Output(struct container* list, ofstream& ofst) {
		if (list->size == 0) {
			cout << "|List is empty!|" << endl;
			return;
		}
		ofst << "Container contains " << list->size << " elements." << endl;
		cout << "|Container contains " << list->size << " elements.|" << endl;
		for (int i = 0; i < list->size; i++) {
			if (!node_Output(list->head, i, ofst)) {
				cout << "Error in node #" << i << " output" << endl;
			}
		}
	}
}