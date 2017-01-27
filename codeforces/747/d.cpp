#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, k;
int v[MAX];
vector<pii> gap;

bool cmp(pii a, pii b) {
    if (a.ss - a.ff <= b.ss - b.ff) return true;
    return false;
}

int main () {
    scanf(" %d %d", &n, &k);
    int neg = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &v[i]);
        if (v[i] < 0) neg++;
    }
    if (neg > k) printf("-1\n");
    else {
        k -= neg;
        int l = -1;
        bool pos = false;
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                if (l == -1) l = i;
                else if (pos) {
                    gap.pb(pii(l, i));     
                    l = i;
                }
                pos = false;
            } else {
                pos = true;
            }
        }
        if (gap.size() > 0) {
            sort(gap.begin(), gap.end(), cmp);
            int len = gap[0].ss - gap[0].ff - 1;
            //printf("k %d len %d\n", k, len);
            for (int i = 0; i < gap.size() && len <= k; i++) {
                for (int j = gap[i].ff + 1; j < gap[i].ss; j++) 
                    v[j] = -1; 
                k -= len;
                if (i + 1 < gap.size()) len = gap[i + 1].ss - gap[i + 1].ff - 1;
            }
            if (l != -1 && n - l - 1 <= k) {
                for (int i = l + 1; i < n; i++) 
                    v[i] = -1;
            }
        }
        int cont = 0, temp = 1;
        for (int i = 0; i < n; i++) {
            //printf("%d ", v[i]);
            if (v[i] * temp < 0 || (v[i] * temp == 0 && (v[i] < 0 || temp < 0))) cont++;
            temp = v[i];
        }
        printf("%d\n", cont);
    }
}

