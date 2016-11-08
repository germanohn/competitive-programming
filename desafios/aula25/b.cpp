#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;


int main() {
    int topo = 0;
    char pilha[MAX];
    char s[MAX];

    scanf(" %s", s);

    for (int i = 0; s[i] != 0; i++) {
        if (topo == 0) {
            pilha[0] = s[i], topo++;
            continue;
        }
        if (s[i] == '(') {
            pilha[topo] = s[i], topo++;;
        } else {
            if (pilha[topo - 1] == '(')
                topo--;
            else pilha[topo] = s[i], topo++;
        }
    }

    printf("%d\n", strlen(s) - topo);
}   
