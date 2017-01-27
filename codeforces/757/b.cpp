#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int v[MAX], freq[MAX], p[MAX], seen[MAX];

void sieve() {
    p[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) {
            for (int j = i; j < MAX; j += i) {
                p[j] = i;
            }
        }
    }
}

int main () {
    sieve();
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    int turn = 1;
    for (int i = 0; i < n; i++) {
        int aux = v[i];
        while (aux > 1) {
            if (seen[p[aux]] < turn) 
                freq[p[aux]]++;
            seen[p[aux]] = turn;
            aux /= p[aux];
        }
        turn++;
    }
    int q = 1;
    for (int i = 2; i < MAX; i++) 
        q = max(q, freq[i]);
    printf("%d\n", q);
}

