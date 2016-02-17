#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, v[30];
ll ans;
set<int> s;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)  
        scanf ("%d", &v[i]);
    sort (v, v + n);
    for (int i = 0; i < n; i++) {
        if (s.find (v[i]) == s.end ()) 
            ans += v[i], s.insert (v[i]);
        else {
            for (int num = v[i]-1; num >=1; num--) {
                if (s.find (num) == s.end ()) {
                        ans += num, s.insert (num); 
                        break;
                }
            }
        }    
    }
    cout << ans << endl;
}
