#include<cstdio>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 26, "n");
    inf.readSpace();
    int k = inf.readInt(1, 100000, "k");
    inf.readEoln();
    for (int submission = 0; submission < k; submission++) {
        char letter = inf.readChar();
        ensuref(letter >= 'A' && letter <= 'A' + n - 1, "letter has to be in the alphabet");
        inf.readSpace();
        int _time = inf.readInt(1, 100000, "_time"); 
        inf.readSpace();
        string veredict = inf.readWord();
        ensuref(veredict == "AC" || veredict == "WA", "only two possible veredicts");
        inf.readEoln();
    }
    inf.readEof();
}

