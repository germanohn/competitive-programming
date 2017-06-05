#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[20];

int main () {
    scanf(" %s", s);
    int len = strlen(s);
    int cont = 0;
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i])
            cont++;
    }
    if ((cont == 1) || (len % 2 == 1 && cont == 0)) 
        printf("YES\n");
    else 
        printf("NO\n");
}

