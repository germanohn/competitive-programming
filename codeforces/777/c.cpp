#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, m;
int row[N];
vector<vector<int> > t;

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int a;
            scanf(" %d", &a);
            row.pb(a);
        }
        t.pb(row);
    }

    row[0] = 1;
    for (int j = 0; j < m; j++) {
        int st = -1, cont = 1;
        for (int i = 1; i < n; i++) {
            if (t[i][j] >= t[i - 1][j]) {
                if (st == -1) st = i - 1;
                cont++;
            } else {
                row[i] = max(row[i], 1);
                if (st != -1) {
                    for (int l = st; l <= i; l++) 
                        row[l] = max(row[l], cont - (l - st));
                }
                st = -1, cont = 1;
            }
        }
        if (st != -1) {
            for (int l = st; l < n; l++) 
                row[l] = max(row[l], cont - (l - st));
        }
    }

    int k;
    scanf(" %d", &k);
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        l--, r--;
        if (row[l] >= (r - l + 1)) 
            printf("Yes\n");
        else printf("No\n");
    }
}

