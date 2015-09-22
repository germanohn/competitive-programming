#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, d, i, j;
long long int ans, maxi;
pair<int, int> fr[MAX];

int main () {
    scanf ("%d %d", &n, &d);
    for (i = 0; i < n; i++) 
        scanf ("%d %d", &fr[i].first, &fr[i].second);
    
    sort (fr, fr + n);
   
    /*primeira versao
    ans = 0, ind = 0;
    for (int i = 0; i < n; i++) {
        for (;fr[ind].first - fr[i].first < d && ind < n; ind++) 
            ans += fr[ind].second;
        if (ans > maxi)
            maxi = ans;
        ans -= fr[i].second;
        
    }
    cout << maxi << endl;*/
    
    ans = 0, i = 0, j = 0;
    while (i < n && j < n) {
        if (fr[j].first - fr[i].first < d) {
            ans += fr[j].second;
            j++;
        }
        else {
            if (ans > maxi)
                maxi = ans;
            ans -= fr[i].second;
            i++;
        }
    } 
    if (ans > maxi)
        maxi = ans;
    cout << maxi << endl;
}
