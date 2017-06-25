#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e3 + 5;

int L, S, M, D, B;
int s[N], m[N], d[N], b[N];
vector<int> sum;

int main() {
    while (scanf(" %d %d %d %d %d", &L, &S, &M, &D, &B)) {
        if (L == 0 && S == 0 && M == 0 && D == 0 && B == 0)
            break;
        for (int i = 0; i < S; i++) 
            scanf(" %d", &s[i]);
        sort(s, s + S);
        for (int i = 0; i < M; i++)
            scanf(" %d", &m[i]);
        sort(m, m + M);
        for (int i = 0; i < D; i++)
            scanf(" %d", &d[i]);
        sort(d, d + D);
        for (int i = 0; i < B; i++)
            scanf(" %d", &b[i]);
        sort(b, b + B);

        sum.clear();
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < B; j++) {
                int a = d[i] + b[j];
                sum.pb(a);    
            }
        }
        sort(sum.begin(), sum.end());

        ll ans = 0;
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < M; j++) {
                int rest = L - (s[i] + m[j]);
                if (rest < 0) 
                    break;
                
                ll p = upper_bound(sum.begin(), sum.end(), rest) - sum.begin();
                ans += p;
            }
        }

        printf("%lld\n", ans);
    }
}
