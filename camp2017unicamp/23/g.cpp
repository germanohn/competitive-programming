#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

const int N = 1e5 + 5;
const int M = 5e4 + 5;

int n, m;
int eq[N + M];
ll bit[N + M]; 
pli v[N];
pil ch[M];
vector<pli> f;
set<pli> s;

void update(int idx, ll val) {
    for (int i = idx; i < N + M; i += i & -i)
        bit[i] += val;
}

ll query(int idx) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int calc() {
    ll sum = 0;
    int ans = 0, pos = 0;
    while (true) {
        auto x = s.lower_bound(pli(sum, pos));
        if (x == s.end()) 
            break;
        if (query((*x).ss) >= 2 * query((*x).ss - 1)) 
            ans++;
        sum = query((*x).ss);
        pos = (*x).ss + 1;
    }
    return ans;
}

void change(int i) {
    int cur = ch[i].ff - 1;
    s.erase(pli(v[cur].ff, v[cur].ss));
    update(v[cur].ss, -v[cur].ff);
    v[cur].ff = ch[i].ss;
    v[cur].ss = eq[i + n];
    update(v[cur].ss, v[cur].ff);
    s.insert(pli(v[cur].ff, v[cur].ss));
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i].ff);
        f.pb(pli(v[i].ff, i));
    }

    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %d %lld", &ch[i].ff, &ch[i].ss);
        f.pb(pli(ch[i].ss, n + i));
    }

    sort(f.begin(), f.end());

    // eq: dira qual o valor comprimido do i-ésimo numero que apareceu
    for (int i = 0; i < f.size(); i++) 
        eq[f[i].ss] = i + 1;

    for (int i = 0; i < n; i++) {
        v[i].ss = eq[i];
        s.insert(pli(v[i].ff, eq[i]));
        update(eq[i], v[i].ff);
    }

    printf("%d\n", calc());
    for (int i = 0; i < m; i++) {
        change(i);
        printf("%d\n", calc());
    }
}







