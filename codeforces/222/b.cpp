#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m, k;
int r[MAX], c[MAX];
int t[MAX][MAX];

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf(" %d", &t[i][j]);
    for (int i = 0; i < n; i++) r[i] = i;
    for (int j = 0; j < m; j++) c[j] = j;
    for (int i = 0; i < k; i++) {
        char ch;
        int x, y;
        scanf(" %c %d %d", &ch, &x, &y);
        x--, y--;
        if (ch == 'g') {
            printf("%d\n", t[r[x]][c[y]]);
        } else if (ch == 'r') {
            swap(r[x], r[y]);
        } else {
            swap(c[x], c[y]);
        }
    }
}

