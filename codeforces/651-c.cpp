#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii v[200005];
int N;
map<pii, int> nome;

bool cnomeX (pii a, pii b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cnomeY (pii a, pii b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int main () {
    scanf ("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf ("%d %d", &v[i].x, &v[i].y);
        pii num = pii (v[i].x, v[i].y);
        if (nome.find (num) != nome.end ()){
            nome[num]++;
        } else {
            nome[num] = 1;
        }
    }
    sort (v, v+N, cnomeX);
    ll ans = 0;
    int now = v[0].x;
    int l = 0;
        ll quant;
    for (int i = 1; i < N; i++) {
        if (v[i].x != now) {
            ll quant = i - l;
            ans += (quant * (quant - 1) / 2);
            l = i;
            now = v[i].x;
        }
    }
    quant = N - l;
    ans += (quant * (quant - 1) / 2);
    sort (v, v+N, cnomeY);
    now = v[0].y;
    l = 0;
    for (int i = 1; i < N; i++) {
        if (v[i].y != now) {
            quant = i - l;
            ans += (quant * (quant - 1) / 2);
            l = i;
            now = v[i].y;
        }
    }
    quant = N - l;
    ans += (quant * (quant - 1) / 2);
    map<pii, int>::iterator it;
    for (it = nome.begin (); it != nome.end (); it++) {
        int c = it->second;
        quant = ll (c);
        ans -= (quant * (quant - 1) / 2);
    }
    cout << ans << "\n";
}

