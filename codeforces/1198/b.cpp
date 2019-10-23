#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int a[N], payout[N], max_payout[N];
pair<int, int> ult_receipt[N];

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }

    int q;
    scanf(" %d", &q);
    for (int i = 1; i <= q; i++) {
        int e;
        scanf(" %d", &e);

        if (e == 1) {
            int p, x;
            scanf(" %d %d", &p, &x);
            ult_receipt[p] = make_pair(i, x);   
        } else {
            int x;
            scanf(" %d", &x);
            payout[i] = x;
        }
    }

    for (int i = q; i >= 1; i--) {
        max_payout[i] = max(max_payout[i + 1], payout[i]);
    }

    for (int i = 1; i <= n; i++) {
        int ans_i = a[i];
        if (ult_receipt[i].first > 0) {
            ans_i = ult_receipt[i].second; 
        }
        ans_i = max(ans_i, max_payout[ult_receipt[i].first + 1]);

        printf("%d ", ans_i);
    }
    printf("\n");
}

