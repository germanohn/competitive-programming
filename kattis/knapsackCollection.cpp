#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e3 + 5;
const int M = 1e7 + 5;
const ll inf = 1e15;

int n, s, t;
int v[N]; 
ll cost[M];
multiset<int> ms;
set<int> st;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main () {
    scanf(" %d %d %d", &n, &s, &t);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        st.insert(v[i]);
    }

    ll _min = inf, _max = 0, aver = 0;
    for (auto i = st.begin(); i != st.end(); i++) {
        int from = *i;
        for (int j = 0; j < n; j++) 
            ms.insert(v[j]);

        int cur = from;
        ll cont = 0;
        while (!ms.empty()) {
            if (ms.find(cur) != ms.end()) {
                ms.erase(ms.find(cur));
                cur = (cur + t) % s;
                cont += ll(t);
            } else {
                auto it = ms.lower_bound(cur);
                if (it == ms.end())
                    it = ms.begin();
                int nx = *it;
                if (nx > cur)
                    cont += ll(nx - cur);
                else 
                    cont += ll(s - cur + nx);
                cur = nx;
            }
        }
        cost[from] = cont;

        _min = min(_min, cont);
        _max = max(_max, cont);
        aver += cont;
    }

    for (int i = 0; i < n; i++)
        ms.insert(v[i]);
    for (int i = 0; i < s; i++) {
        if (ms.find(i) != ms.end())
            continue;
        auto it = ms.lower_bound(i);
        if (it == ms.end())
            it = ms.begin();
        int nx = *it;
        ll cont = 0;
        if (nx > i)
            cont = ll(nx - i + cost[nx]);
        else 
            cont = ll(s - i + nx + cost[nx]);

        _min = min(_min, cont);
        _max = max(_max, cont);
        aver += cont;
    }

    ll d = gcd(aver, s);
    printf("%lld %lld %lld/%lld\n", _min, _max, aver / d, s / d);
}

