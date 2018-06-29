#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int pans = ouf.readInt(0, 10000000, "total penalty");
    
    int jans = ans.readInt(); // We suppose that jury's answer is correct
    
    if (pans == jans)
        quitf(_ok, "The penalty is correct"); // This finishes checker with verdit OK.
    else
        quitf(_wa, "The penalty is wrong: expected = %d, found = %d", jans, pans);
}

