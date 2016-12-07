#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 305;

int n, turn;
int p[MAX], pai[MAX], sz[MAX]; 
char A[MAX][MAX];

int find(int a) {
    if (a == pai[a]) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    pai[b] = pai[a];
    sz[a] += sz[b];
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
        pai[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &A[i][j]);
            if (A[i][j] == '1') 
                join(i, j);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int min_p = p[i], pos = i;
        for (int j = i + 1; j < n; j++) {
            if (find(i) == find(j) && p[j] < min_p)
                min_p = p[j], pos = j;
        }
        swap(p[i], p[pos]);
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", p[i]);
    printf("\n");
}

