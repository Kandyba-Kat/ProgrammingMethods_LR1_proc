#include <iostream>
#include <fstream>
#include "node.h"
#include "phrase.h"
#include "container.h"

namespace type_phrases {
	// сигнатура
	int num_punct_marks(struct phrase* phrase);

	bool node_Add(struct container* currentList, ifstream& ifst) {
		struct node* newNode = new node;
		newNode->info = phrase_Input(ifst);
		if (newNode->info == 0) {
			delete(newNode);
			return false;
		}
		if (currentList->head == NULL) {
			currentList->head = newNode;
			currentList->tail = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else {
			newNode->next = NULL;
			newNode->prev = currentList->tail;
			currentList->tail->next = newNode;
			currentList->tail = newNode;
		}
		return true;
	}

	bool node_Output(struct node* headNode, int pos, ofstream& ofst) {
		node* currentNode = get_node(headNode, pos);
		if (!phrase_Output(currentNode->info, ofst)) {
			cout << "Cannot to output phrase!" << endl;
			return false;
		}
		else {
			ofst << "Number of punctuation marks: " << num_punct_marks(currentNode->info) << "." << endl;
			return true;
		}
		
	}

	struct node* get_node(struct node* head, int index) {
		struct node* curNode = head;
		for (int i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		return curNode;
	}
}