#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int freq[55][55];
pii v[55];

bool cmp(pii a, pii b) {
    if (a.ff != b.ff) 
        return a.ff > b.ff;
    else 
        return a.ss < b.ss;
}

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].ff, &v[i].ss);
        freq[v[i].ff][v[i].ss]++;
    }
    sort(v, v + n, cmp);
    printf("%d\n", freq[v[k - 1].ff][v[k - 1].ss]);
}

