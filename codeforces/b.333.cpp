#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int ans, v[MAX];

int main () {
    int n; 
    scanf ("%d", &n); 
    multiset<int> ms;
    int ini = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        ms.insert (v[i]);
        while (*ms.rbegin() - *ms.begin() > 1) 
            ms.erase(ms.find (v[ini++]));
       
        ans = max (ans, i-ini+1);
    }
    printf ("%d\n", ans);
}
