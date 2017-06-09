/* 
 * Esse programa gera todas as permutações de uma dada string sem printar as 
 * repetições 
 */

#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 65;

int n;
char s[N], p[N];

void go(int i, int mask) {
    if (s[i] == 0) 
        printf("%s\n", p);

    int seen = 0;
    for (int j = 0; j < n; j++) {
        if (((1 << (s[j] - 'a')) & seen) == 0 && ((1 << j) & mask) == 0) {
            seen |= (1 << (s[j] - 'a'));
            p[i] = s[j];
            go(i + 1, mask | (1 << j));
        }
    }
}

int main () {
    scanf(" %s", s);
    n = strlen(s);
    go(0, 0);
}

