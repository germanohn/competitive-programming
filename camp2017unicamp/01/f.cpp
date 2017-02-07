#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, f;
int e[123], seen[123], pres[123];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &f);
    for(int i = 0; i < n; i++) { 
        scanf("%d", e+i);
        pres[e[i]] = 1;
    }
    int count = n;
    int last = 0;
    vector<int> ans;
    while(count) {
        while(seen[e[last]]) last++;
        int go = e[last];
        if(f < go) f++;
        else f--;   
        if(pres[f] && !seen[f]) { 
            ans.pb(f);
            count--;
        }
        seen[f] = true;
    }
    for(int v : ans) printf("%d ", v);
    putchar('\n');
}

