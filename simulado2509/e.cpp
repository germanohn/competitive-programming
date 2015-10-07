#include <bits/stdc++.h>
#define MAX 25010
#define ff first
#define ss second

using namespace std;

int n, t, ult[MAX];
char v[MAX], c;
map<char, int> m;

int main () {
    scanf ("%d", &t);
    
    while (t--) {
        scanf("%d",&n);
        
        int k = 0;
        m.clear();
        for (int i = 0; i < n; i++) {
            scanf (" %c", &c);
            v[i] = c;
            if(m.find(c) == m.end()) m[c] = k++;
            ult[m[c]] = i;
        }
        
        int podre, ans;
        ans = podre = 0;
        for (int i = 0; i < n; i++) 
            podre += 5 * (ult[m[v[i]]] - i);
        sort (v, v + n);

        k = 0;
        m.clear ();
        for (int i = 0; i < n; i++) {
            if (m.find (v[i]) == m.end ()) m[v[i]] = k++;
            ult[m[v[i]]] = i;
        }
        for (int i = 0; i < n; i++) 
            ans += 5 * (ult[m[v[i]]] - i);
    
        printf ("%d\n", podre - ans);
    }
}
