#include "node.h"

namespace type_phrases {
	// сигнатуры требуемых функций
	int num_punct_marks(struct phrase* phrase);

	bool compare(struct phrase* first, struct phrase* second) {  
		return num_punct_marks(first) > num_punct_marks(second); // в порядке неубывания 
	}

	void swap(struct node* head, int ind_first, int ind_second) {
		struct node* temp = new node;
		temp->info = Get_Node(head, ind_first)->info;
		Get_Node(head, ind_first)->info = Get_Node(head, ind_second)->info;
		Get_Node(head, ind_second)->info = temp->info;
	}

	void Sort(int size, struct node* head) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i+1; j < size; j++) {
				if (compare(Get_Node(head, i)->info, Get_Node(head, j)->info)) {
					swap(head, i, j);
				}
			}
		}
	}
}