#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int p1[MAX], p2[MAX];
pii v[MAX];

bool cmp(int a, int b) {
    if (v[a].ss != v[b].ss) return v[a].ss < v[b].ss;
    return v[a].ff < v[b].ff;
}

bool cmp2(int a, int b) {
    if (v[a].ff != v[b].ff) return v[a].ff < v[b].ff;
    return v[a].ss < v[b].ss;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].ff, &v[i].ss);
        p1[i] = i, p2[i] = i;
    }
    sort(p1, p1 + n, cmp2);
    sort(p2, p2 + n, cmp);
    bool ans = false;
    for (int i = 0; !ans && i < n; i++) {
        if (p1[i] != p2[i])
           ans = true; 
    }
    if (ans) printf("Happy Alex\n");
    else printf("Poor Alex\n");
}

