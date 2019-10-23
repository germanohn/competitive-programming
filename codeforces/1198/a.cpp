#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 4e5 + 5;

int n, I;
int a[N], freq_acc[N];

bool fit(int l, int r) {
    int disk_size = 8 * I;
    int K = r - l + 1;
    int k = 0;
    for (; k <= 19; k++) {
        if (K <= (1 << k))
            break;
    }
    int disk_used = n * k;

    return disk_used <= disk_size;
}

int main() {
    scanf(" %d %d", &n, &I);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    sort(a, a + n);

    vector<int> ua (a, a + n);
    vector<int>::iterator sz;
    sz = unique(ua.begin(), ua.end());
    ua.resize(distance(ua.begin(), sz));

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != ua[cur]) {
            cur++;
            freq_acc[cur] += freq_acc[cur - 1];
        }
        freq_acc[cur]++;
    }

    int min_changes = n;
    for (int l = 0; l < ua.size(); l++) {
        if (!fit(l, l)) 
            continue;

        int lo = l, hi = ua.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi + 1) / 2;
            if (fit(l, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        int r = lo;

        int qtd_above_r = freq_acc[ua.size() - 1] - freq_acc[r];
        int qtd_below_l = l ? freq_acc[l - 1] : 0;
        min_changes = min(min_changes, qtd_above_r + qtd_below_l);
    }

    printf("%d\n", min_changes);
}

