#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n;
char s[MAX];
set<int> d, r;

int main () {
    scanf(" %d %s", &n, s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') 
            d.insert(i);
        else 
            r.insert(i);
    }
    int nx_pos = 0;
    while (d.size() != 0 && r.size() != 0) {
        set<int>::iterator dep, rem;
        dep = d.lower_bound(nx_pos);
        rem = r.lower_bound(nx_pos);
        if (dep == d.end() && rem == r.end()) {
            nx_pos = 0;
        } else if (rem == r.end() || (dep != d.end() && *dep < *rem)) {
            if (rem == r.end()) r.erase(r.begin());
            else r.erase(rem);
            nx_pos = *dep + 1;
        } else if (dep == d.end() || (rem != r.end() && *rem < *dep)) {
            if (dep == d.end()) d.erase(d.begin());
            else d.erase(dep);
            nx_pos = *rem + 1;
        }
    }
    if (d.size() == 0) 
        printf("R\n");
    else 
        printf("D\n");
}

