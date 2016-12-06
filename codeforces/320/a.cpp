#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    char s[15];
    scanf(" %s", s);
    int four = 0;
    bool magic = true, f = false;
    for (int i = 0; magic && s[i] != 0; i++) {
        if (s[i] != '1' && s[i] != '4') magic = false;
        if (s[i] == '1') f = true, four = 0;
        else if (s[i] == '4') four++;
        if (!f || four > 2) magic = false;
    }
    if (magic) printf("YES\n");
    else printf("NO\n");
}

