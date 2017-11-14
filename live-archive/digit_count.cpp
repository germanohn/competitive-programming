#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100;

int cur, a, b;
ll ans[N];
ll me[N][2][2];
char s[N];

ll dp(int i, bool eq, bool noLead) {
    if (s[i] == 0) return 1;
    ll &mm = me[i][eq][noLead];
    if (mm != -1) return mm;

    ll aux = 0;
    for (int j = 0; j < 10; j++) {
        if (eq && j > s[i] - '0')
            break;
        //printf("i %d eq %d noLead %d j %d aux %d\n", i, eq, noLead, j, aux);
        aux += (((noLead || j) && (j == cur)) * dp(i + 1, eq && (j == (s[i] - '0')), (j || noLead)));
    }

    return mm = aux;
}

int main () {
    while (scanf(" %d %d", &a, &b)) {
        if (!a && !b)
            break;

        sprintf(s, "%d", b);
        puts(s);
        for (int i = 0; i < 10; i++) {
            memset(me, -1, sizeof me);
            cur = i;
            ans[i] = dp(0, true, false);
        }
        for (int i = 0; i < 10; i++)
            printf("%lld%c", ans[i], i == 9 ? '\n' : ' ');

        sprintf(s, "%d", a - 1);
        puts(s);
        for (int i = 0; i < 10; i++) {
            memset(me, -1, sizeof me);
            cur = i;
            ans[i] = dp(0, true, false);
        }

        for (int i = 0; i < 10; i++) 
            printf("%lld%c", ans[i], i == 9 ? '\n' : ' ');
    }
}

