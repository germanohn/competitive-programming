#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k, q;
int fl[N], fr[N];
int freq[N];
int sum[N];

int main () {
    scanf(" %d %d %d", &n, &k, &q);

    for (int i = 0; i < n; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        fl[l]++;
        fr[r]++;
    }

    int cur = 0;
    for (int i = 0; i < N; i++) {
        cur += fl[i];
        freq[i] += cur;

        cur -= fr[i];
    }

    for (int i = 1; i < N; i++) {
        if (freq[i] >= k)
            sum[i]++;
        sum[i] += sum[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
}

