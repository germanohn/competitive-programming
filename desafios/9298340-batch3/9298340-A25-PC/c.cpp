#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

int main() {
    char s[MAX];
    int topo = 0, ch = 0;
    char pilha[MAX];
    scanf(" %s", s);

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{' || s[i] == '<')
            pilha[topo] = s[i], topo++;
        else {
            if (topo == 0) {
                printf("Impossible\n");
                return 0;
            }
            if (s[i] == ']' && pilha[topo - 1] != '[') ch++; 
            else if (s[i] == ')' && pilha[topo - 1] != '(') ch++; 
            else if (s[i] == '}' && pilha[topo - 1] != '{') ch++; 
            else if (s[i] == '>' && pilha[topo - 1] != '<') ch++; 
            topo--;
        }    
    }
    if (topo != 0) printf("Impossible\n");
    else printf("%d\n", ch);
}
