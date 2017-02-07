#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 30;

int n;
char s[MAX];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);
        int l = strlen(s);
        if ((s[l - 2] == 'c' && s[l - 1] == 'h') || 
            s[l - 1] == 'x' || s[l - 1] == 's' || s[l - 1] == 'o') {
            s[l] = 'e', s[l + 1] = 's', s[l + 2] = 0;
        } else if ((s[l - 2] == 'f' && s[l - 1] == 'e') || s[l - 1] == 'f') {
            if (s[l - 2] == 'f' && s[l - 1] == 'e') {
                s[l - 2] = 'v', s[l - 1] = 'e', s[l] = 's', s[l + 1] = 0;
            } else {
                s[l - 1] = 'v', s[l] = 'e', s[l + 1] = 's', s[l + 2] = 0;
            }
        } else if (s[l - 1] == 'y') {
            s[l - 1] = 'i', s[l] = 'e', s[l + 1] = 's', s[l + 2] = 0;
        } else {
            s[l] = 's', s[l + 1] = 0;
        }
        printf("%s\n", s);
    }
}

