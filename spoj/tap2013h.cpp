#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e6 + 5;

int t;
int p[N];
set<int> d;
vector<int> v[N];

void sieve() {
        for (int i = 2; i * i < N; i++) {
                if (!p[i]) {
                        for (int j = i * i; j < N; j += i)
                                p[j] = i;
                        p[i] = i;
                }
        }
        for (int i = 2; i < N; i++) {
                if (!p[i]) p[i] = i;
        }
}

int main() {
        sieve();
        scanf(" %d", &t);
        for (int i = 2; i < N; i++) {
                int cont = 1;
                int x = i;
                while (p[x] != x) {
                        d.clear();
                        while (x > 1) {
                                d.insert(p[x]);
                                x /= p[x];
                        }       
                        int sum = 0;
                        for (auto it = d.begin(); it != d.end(); it++) 
                                sum += *it;
                        x = sum;
                        cont++;
                }
                v[cont].pb(i);
        }

        while (t--) {
                int a, b, k;
                scanf(" %d %d %d", &a, &b, &k);
                int l, r;
                r = upper_bound(v[k].begin(), v[k].end(), b) - v[k].begin();
                l = lower_bound(v[k].begin(), v[k].end(), a) - v[k].begin();                                    
                printf("%d\n", r - l);
        }       
}

