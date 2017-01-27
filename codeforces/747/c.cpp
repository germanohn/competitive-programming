#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, q;
int server[105], ans[MAX];

int main () {
    scanf(" %d %d", &n, &q);
    for (int j = 0; j < q; j++) {
        int t, k, d;
        scanf(" %d %d %d", &t, &k, &d);
        int cont = 0;
        for (int i = 0; i < n; i++) 
            if (server[i] < t) cont++;
        if (cont >= k) {
            for (int i = 0; k && i < n; i++) {
                if (server[i] < t) 
                    server[i] = t + d - 1, k--, ans[j] += i + 1;
            }
        } else {
            ans[j] = -1;
        }
    }
    for (int i = 0; i < q; i++) 
        printf("%d\n", ans[i]);
}

