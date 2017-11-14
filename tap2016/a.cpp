#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[25];
    while (scanf(" %s", s) != EOF) {
        bool f = true;
        for (int i = 0; f && s[i] != 0; i++) {
            if (s[i] == 'i') 
                f = false;
        }
        if (f) printf("S\n");
        else printf("N\n");
    }
}

