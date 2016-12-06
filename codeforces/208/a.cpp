#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[205];
bool forbid[205];

int main () {
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'U' && s[i - 1] == 'W' && s[i + 1] == 'B')
           forbid[i - 1] = true, forbid[i] = true, forbid[i + 1] = true; 
    }
    bool f = false;
    for (int i = 0; s[i] != 0; i++) {
        if (!forbid[i])
            printf("%c", s[i]), f = true;
        else if (f)
            printf(" "), f = false;
    }
    printf("\n");
}

