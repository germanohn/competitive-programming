#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    char s[55]; 
    scanf(" %d", &n);
    scanf(" %s", s);

    int cont = 0;
    char at = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == at) 
            cont++;
        at = s[i];
    }

    printf("%d\n", cont);
}

