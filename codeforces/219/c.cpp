#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500005;

int n, k;
char s[MAX];

int main () {
    scanf(" %d %d %s", &n, &k, s + 1);
    s[0] = 'a';
    int cont = 0;
    for (int i = 1; s[i] != 0; i++) {
        if (s[i] == s[i - 1]) {
            char c;
            if (c != s[i - 1] && c != s[i + 1]) 
                cont++, s[i] = c;
            else {
                for (c = 'A'; c - 'A' <= k; c++) {
                    if (c != s[i - 2] && c != s[i]) 
                        break;
                }
                if (c != s[i - 2] && c != s[i]) 
                    cont++, s[i - 1] = c;
                else {
                    cont += 2;
                    if (s[i] == 'A') s[i] = 'B', s[i + 1] = 'A';
                    else s[i] = 'A', s[i + 1] = 'B';
                }
            }
        }
    }
    printf("%d\n%s\n", cont, s + 1);
}

