#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[10], freq[10];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x; 
        scanf(" %d", &x);
        a[x]++;
        freq[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf(" %d", &x);
        freq[x]++;
    }

    bool ok = true;
    int ans = 0;
    for (int i = 1; ok && i <= 5; i++) {
        if (freq[i] % 2 != 0) 
            ok = false;
        else 
            ans += abs(a[i] - freq[i] / 2);
    }

    if (ok) printf("%d\n", ans / 2);
    else printf("-1\n");
}

