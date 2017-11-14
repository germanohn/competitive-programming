#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int inf = 1e9 + 5;

int n;
int a[N];
int l[N], r[N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &a[i]);

    int cont = 1;
    l[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) cont++;
        else cont = 1;
        l[i] = cont;
    }

    cont = 1;
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) cont++;
        else cont = 1;
        r[i] = cont;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (!i) 
            ans = max(ans, 1 + r[i + 1]);
        else if (i == n - 1)
            ans = max(ans, 1 + l[i - 1]);
        else if (a[i - 1] < a[i + 1] - 1)
            ans = max(ans, l[i - 1] + r[i + 1] + 1);
        else 
            ans = max(ans, l[i - 1] + 1);
    }

    printf("%d\n", ans);
}
