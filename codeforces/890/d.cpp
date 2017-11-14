#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int n;
bool match_pref[N];
vector<string> l;
vector<int> adj[N];

bool match(int a, int b) {
    bool ok = false;
    int k = 0;
    for (int i = 0; l[a][i] != 0 && l[b][k] != 0; i++) {
        if (l[a][i] == l[b][k]) {
            ok = true;
            k++;
        } else {
            ok = false;
            k = 0;
        }

        if (l[b][k] == 0 && l[a][i + 1] != 0) {
            l.erase(l.begin() + b);
            ok = false;
        }
    }

    return ok;
}

void add_edge(int a, int b) {
    // suf[a] == pref[b]
    if (match(a, b)) {
        adj[a].pb(b);
        match_pref[b] = true;
    } 
    if (match(b, a)) {
        adj[b].pb(a);
        match_pref[a] = true;
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        l.pb(s);
    }

    sort(l.begin(), l.end());

    if (l.size() > 26) {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < l.size(); i++) {
        for (int j = i + 1; j < l.size(); j++) {
            add_edge(i, j);
        }
    }

    string ans;
    int cur = -1;
    for (int i = 0; i < l.size(); i++) {
        if (!match_pref[i]) {
            cur = i;
            ans = l[i];
        }
    }
    
    if (cur == -1) {
        printf("NO\n");
        return 0;
    } 

    int cont = 1;
    while (cont < l.size()) {
        if (adj[cur].size() > 1) {
            printf("NO\n");
            return 0:
        } else {
            for (int i = 0; l[a][i] != 0 && l[b][k] != 0; i++) {
                if (l[a][i] == l[b][k]) {
                    k++;
                } else {
                    k = 0;
                }
            } 

            while (l[b][k] != 0) {
                ans += l[b][k];
                k++;
            }

            cur = b, cont++;
        }
    }

    cout << ans << endl;
}

