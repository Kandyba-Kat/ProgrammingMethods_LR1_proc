#ifndef  CONTAINER_H
#define CONTAINER_H
#include <fstream>
#include <string>

using namespace std;

namespace type_phrases {
	struct node;

	struct container { // list type
		int size;
		node* head; // pointer to the first item in the list
		node* tail;
	};

	void Container_Init(container* list);
	void Container_Clear(struct container* list);
	void Container_Fill(struct container* list, ifstream& ifst);
	void Container_Output(struct container* list, ofstream& ofst);
} // end type_phrases namespace
#endif // CONTAINER_H

