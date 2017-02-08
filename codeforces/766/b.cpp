#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    bool ok = false;
    int cont = 0;
    for (int i = 0; !ok && i < n - 2; i++) {
        cont++;
        if ((v[i + 1] - v[i]) < v[i + 2] && (v[i] + v[i + 1]) > v[i + 2])
            ok = true;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
}

