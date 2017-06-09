#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int v[N];
set<int> ans;
map<int, int> freq;

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    sort(v, v + n);
    for (int i = 0; i < n - 1; i++) 
        mp[v[i + 1] - v[i]]++;

    if (n == 1) {
        printf("-1\n");
    } else if (mp.size() == 1) {
        auto it = mp.begin();
        ans.insert(v[0] - it->first);
        ans.insert(v[n - 1] + it->first);
        if (n == 2 && (v[0] + v[1]) % 2 == 0) 
            ans.insert((v[0] + v[1]) / 2);
    } else if (mp.size() > 2) {
        printf("0\n");
    } else {
        auto it = mp.begin();
        
    }
}
