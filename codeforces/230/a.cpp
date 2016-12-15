#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int s, n;
pii v[1005];

int main () {
    scanf(" %d %d", &s, &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d %d", &v[i].ff, &v[i].ss); 
    sort(v, v + n);
    bool ans = true;
    for (int i = 0; ans && i < n; i++) {
        if (s > v[i].ff) 
            s += v[i].ss;
        else 
            ans = false;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}

