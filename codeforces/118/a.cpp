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
    for (int i = 0; s[i] != 0; i++) 
        s[i] = tolower(s[i]);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] != 'a' && s[i] != 'o' && s[i] != 'y' && s[i] != 'e' &&
            s[i] != 'u' && s[i] != 'i') 
            printf(".%c", s[i]);
    }
    printf("\n");
}

