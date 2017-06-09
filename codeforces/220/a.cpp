#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int a[N], b[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            cont++;
    }
    if (cont <= 2) printf("YES\n");
    else printf("NO\n");
}

