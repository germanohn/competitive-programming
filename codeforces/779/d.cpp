#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int len_t, len_p;
int seen[N];
char t[N], p[N];

bool ok(int ini) {
    int pos_p = 0;
    for (int i = 0; i < len_t && pos_p < len_p; i++) {
        if (seen[i] >= ini && t[i] == p[pos_p])
            pos_p++;
    }
    return pos_p == len_p;
}

int main() {
    scanf(" %s %s", t, p);
    len_t = strlen(t);
    len_p = strlen(p);
    for (int i = 0; i < len_t; i++) {
        int a;
        scanf(" %d", &a);
        a--;
        seen[a] = i;
    }

    int lo = 0, hi = len_t - 1;
    while (lo != hi) {
        int mid = (lo + hi + 1) / 2;
        if (ok(mid))
            lo = mid;
        else 
            hi = mid - 1;
    }

    printf("%d\n", lo);
}
