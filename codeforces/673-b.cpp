#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;

int main () {
    scanf ("%d %d", &n, &m);
    int mx2 = 1, mi1 = n, a, b;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        if (a > b) swap (a, b);
        mx2 = max (mx2, a);
        mi1 = min (mi1, b);
    }
    int ans = mi1 - mx2;
    if (ans <= 0) 
        printf ("0\n");
    else 
        printf ("%d\n", ans);
}

/*
const int MAX = 100005;

int n, m;
bool mark[MAX];
set<int> div1, div2;

int main () {
    scanf ("%d %d", &n, &m);
    int M2 = -1, m1 = INT_MAX;
    for (int i = 1; i <= n; i++) {
        mark[i] = false;
    }
    int a, b, cont = 0;
    bool f = true;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        if (a > b) swap (a, b);
        if (div1.find (a) == div1.end () && div2.find (b) == div2.end ()) {
            div2.insert (a);
            M2 = max (M2, a);
            div1.insert (b);
            m1 = min (m1, b);
            mark[a] = true;
            mark[b] = true;
        } else {
            f = false;
        }
    }
    ll ans = 1;
    if (m == 0) {
        div2.insert (1);
        div1.insert (n);
        mark[1] = mark[n] = true;
        M2 = 1, m1 = n;
    } 
    if (!f || M2 > m1) {
        printf ("0\n");
        return 0;
    }
    // sobrou gente
    int i = 1;
    for (; i <= M2; i++) {
        if (!mark[i]) 
            mark[i] = true; // entrou na div2 necessariamente
    }
    // dos que sobraram temos so maiores que M2.
    // os entre M2 e m1 multiplica por dois
    // os depois de m1 tem que ir pra div1
    for (int j = i; j <= n; j++) {
        if (!mark[j] && j > M2 && j < m1)
            ans += 1;
    }
    cout << ans << "\n";
}*/
 

