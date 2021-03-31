#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;
namespace type_phrases {
    // Сигнатуры требуемых функций
    void aphorism_Out(struct container* list, ofstream& ofst);
}
using namespace type_phrases;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Incorrect command line!\n"
             << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);
    if (!ifst.is_open()) {
        cout << "File is not open!" << endl;
        exit(1);
    }
    ofstream ofst(argv[2]);

    cout << "Start" << endl;
    container* c = new container;
    container_Init(c);
    container_Fill(c, ifst);
    cout << "Filled container" << endl;
    aphorism_Out(c, ofst);
    cout << "Output of aphorisms only" << endl;
    container_Clear(c);
    cout << "Empty container" << endl;
    container_Output(c, ofst);
    cout << "Stop" << endl;

    system("pause");
    return 0;
}