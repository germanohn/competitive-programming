#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());
    int count = 1;
    int toSpend = v[0];
    reverse(v.begin(), v.end());
    v.pop_back();
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] <= toSpend)
        {
            count++;
            toSpend -= v[i];
        }
        else break;
    }
    cout << count << endl;
    return 0;
}

