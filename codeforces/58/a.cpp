#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    char s[105];
    scanf(" %s", s);
    const char *aux = "hello";
    int p = 0;
    for (int i = 0; s[i] != 0; i++) 
        if (s[i] == aux[p]) p++;
    if (p == 5) printf("YES\n");
    else printf("NO\n");
}

