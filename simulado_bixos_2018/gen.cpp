#include<cstdio>
#include<cstdlib>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int w = atoi(argv[3]);
    vector<int> _time;
    for (int i = 0; i < k; i++) 
        _time.push_back(rnd.wnext(1, 100000, w));
    sort(_time.begin(), _time.end());
    printf("%d %d\n", n, k);
    for (int i = 0; i < k; i++) {
        int letter = rnd.wnext(n, w);
        printf("%c %d %s\n", 'A' + letter, _time[i], rnd.next("AC | WA").c_str());
    }
}

