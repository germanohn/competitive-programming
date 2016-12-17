#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[55];
set<string> ans;

int main () {
    scanf(" %s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        ans.insert(s);
        char aux = s[len - 1];
        for (int j = 1; j < len; j++)
            s[j] = s[j - 1];
        s[0] = aux;
    }
    printf("%d\n", ans.size());
}

