#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int MOD = 1e9 + 7;

ll p;
int t;
int d[4] = {2, 3, 5, 7};
int cont[5];
ll inv[N];
ll fat[N];

ll mod(ll x) {
    return (x + MOD) % MOD;
}

ll fexp(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e % 2 == 0) return fexp(mod(b * b), e / 2);
    return mod(b * fexp(mod(b * b), e / 2));
}

int main () {
    fat[0] = 1;
    for (int i = 1; i <= 100; i++) 
        fat[i] = mod(ll(i) * fat[i - 1]);

    scanf(" %d", &t);
    while (t--) {
        scanf(" %lld", &p);
        if (!p) {
            printf("1\n");
            continue;
        }
        for (int i = 0; i < 4; i++) {
            cont[i] = 0;
            while (p % d[i] == 0) {
                cont[i]++;
                p /= d[i];
            }
        }

        if (p > 1) {
            printf("0\n");
        } else {
            ll ans = 0;
            int eight = floor(cont[0] / 3);
            for (int i = 0; i <= eight; i++) {
                int four = floor((cont[0] - i * 3) / 2);
                for (int j = 0; j <= four; j++) {
                    int two = cont[0] - 3 * i - 2 * j; 

                    int nine = floor(cont[1] / 2);
                    for (int l = 0; l <= nine ; l++) {
                        int three = cont[1] - 2 * l;

                        vector<int> cur;
                        int alpha = 0;
                        //printf("8: %d, 4 : %d, 2 : %d, 9 : %d, 3 : %d\n", eight, four, two, nine, three);
                        cur.pb(i), cur.pb(j), cur.pb(two), cur.pb(l), cur.pb(three), cur.pb(cont[2]), cur.pb(cont[3]);
                        for (int k = 0; k < cur.size(); k++)
                            alpha += cur[k];

                        //printf("alpha %d\n", alpha);
                        printf("alpha %d\n", alpha);
                        int st = max(1, alpha);
                        for (int dig = st; dig <= 100; dig++) {
                            //printf("dig %d\n", dig);
                            ll aux = fat[dig];
                            ll den = 1;
                            for (int k = 0; k < cur.size(); k++) {
                                den = mod(den * fat[cur[k]]);
                            }
                            den = mod(den * fat[dig - alpha]);
                            aux = mod(aux * fexp(den, MOD - 2));
                            //printf("aux %lld\n\n", aux);

                            ans = mod(ans + aux);
                        }
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
}

