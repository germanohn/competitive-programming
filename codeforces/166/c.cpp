#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 505;

int n, x;
int v[MAX];

int main () {
    scanf(" %d %d", &n, &x);
    bool has = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (v[i] == x) has = true;
    }
    if (!has) v[n] = x, n++;
    sort(v, v + n);
    int cont = 2 * n;
    int median = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            int pre, nx;
            pre = i, nx = n - 1 - i;
            if (i < median) {
                cont = min(cont, nx - pre - 1);
            } else if (i == median) {
                cont = 0;
            } else { 
                cont = min(cont, pre - nx);
            }
        }
    }
    printf("%d\n", !has + cont);
}

