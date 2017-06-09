#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[505];
bool seen[26];

int main () {
    scanf(" %s", s);
    int cont = 0;
    bool ans = true;
    for (int i = 0; ans && s[i] != 0; i++) {
        int val = s[i] - 'a';
        if (val > cont) 
            ans = false;
        else if (val == cont)
            cont++;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}

