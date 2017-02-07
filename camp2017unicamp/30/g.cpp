#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<string, int> m;

void add(int i, string key, vector<string> v) {
    if(i == int(v.size())) {
        if(key.length() > 0) m[key]++;
    } else {
        add(i+1, key + v[i], v);
        add(i+1, key, v);
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);      
        vector<string> v;
        for(int j = 0; j < k; j++) {
            string s;
            cin >> s;
            v.pb(s+"$");
        }
        sort(v.begin(), v.end());
        add(0, "", v);
    }
    int mm;
    scanf("%d", &mm);
    for(int i = 0; i < mm; i++) {
        int k;
        scanf("%d", &k);
        vector<string> v;
        for(int j = 0; j < k; j++) {
            string s;
            cin >> s;
            v.pb(s+"$");
        }
        sort(v.begin(), v.end());
        string qry = "";
        for(string s : v) qry += s;
        printf("%d\n", m[qry]);
    }
}

