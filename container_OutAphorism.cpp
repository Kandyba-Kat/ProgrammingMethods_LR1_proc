#include <iostream>
#include <fstream>
#include "container.h"
#include "node.h"
#include "phrase.h"

namespace type_phrases {
	// ????? ?????? ?????????
	void aphorism_Out(struct container* list, ofstream& ofst) {
		node* curNode;
		ofst << "Only aphorism." << endl;
		for (int i = 0; i < list->size; i++) {
			ofst << (i+1) << ": ";
			
            curNode = list->head;
            for (int j = 0; j < i; j++)
            {
                curNode = curNode->next;
            }
            if (curNode->info->key == phrase::type::APHORISM)
            {
                if (!node_Output(list->head, i, ofst))
                {
                    cout << "|Node #" << i << " is broken!|" << endl;
                    ofst << "Node is broken!" << endl;
                }
            }
            else
                ofst << endl;

		}
	}
}