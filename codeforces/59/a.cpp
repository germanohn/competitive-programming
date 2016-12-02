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

    int lo = 0, hi = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') lo++;
        else hi++;
    }

    if (lo >= hi)
        for (int i = 0; s[i] != 0; i++) 
            printf("%c", tolower(s[i]));
    else 
        for (int i = 0; s[i] != 0; i++) 
            printf("%c", toupper(s[i]));
    printf("\n");
}

