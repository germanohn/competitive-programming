#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii v[5];
set<pii> pto;

int main () {
    for (int i = 0; i < 3; i++) 
        scanf(" %d %d", &v[i].ff, &v[i].ss);
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            pii a, b;
            int l;
            for (l = 0; l < 3; l++) 
                if (l != i && l != j) 
                    break;
            a = pii(v[i].ff - v[j].ff, v[i].ss - v[j].ss);
            b = pii(v[j].ff - v[i].ff, v[j].ss - v[i].ss);
            pto.insert(pii(v[l].ff + a.ff, v[l].ss + a.ss));
            pto.insert(pii(v[l].ff + b.ff, v[l].ss + b.ss));
        }
    }
    printf("%d\n", pto.size());
    for (auto it = pto.begin(); it != pto.end(); it++) {
        printf("%d %d\n", (*it).ff, (*it).ss);
    }
}

