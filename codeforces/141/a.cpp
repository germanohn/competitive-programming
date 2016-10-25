#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int freq[150];
char s[150];

int main () {
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]++;
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]++;
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]--;

    bool ok = true;
    for (int i = 0; ok && i < 150; i++) 
        if (freq[i] != 0) ok = false;

    if (ok) printf("YES\n");
    else printf("NO\n");
}

