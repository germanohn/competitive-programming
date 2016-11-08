#include<bits/stdc++.h>
using namespace std;

const int MAX = 130;

int main() {
    int n;
    int topo = 0;
    char s[MAX], pilha[MAX];

    scanf(" %d", &n);
    char c = getchar();
    while (n--) {
        fgets(s, sizeof(s), stdin);
        //printf("%s\n\n", s);
        topo = 0;
        s[strlen(s) - 1] = 0;

        bool ok = true;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == '(' || s[i] == '[') 
                pilha[topo] = s[i], topo++;
            else {
                if (topo == 0) {
                    ok = false;
                    break;
                }
                if (s[i] == ')' && pilha[topo - 1] == '(') {
                    topo--;
                } else if (s[i] == ']' && pilha[topo - 1] == '[') {
                    topo--;
                } else {
                    ok = false;
                    break;
                }
            }
            //printf("topo %d ok %d\n", topo, ok);
        }

        //printf("topo %d ok %d\n", topo, ok);
        if (topo != 0 || !ok) printf("No\n");
        else printf("Yes\n");
    }
}
