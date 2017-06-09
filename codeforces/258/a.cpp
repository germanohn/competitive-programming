#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

char s[MAX];

int main () {
    scanf(" %s", s);
    int forbid = strlen(s) - 1;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '0') {
            forbid = i;
            break;
        }
    }
    for (int i = 0; s[i] != 0; i++) {
        if (i != forbid)
            printf("%c", s[i]);
    }
    printf("\n");
}

