#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

deque<int> dq;
int query[3 * N][2];
vector<int> v;

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        dq.push_back(a);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        a = dq.front();
        dq.pop_front();
        query[i][0] = a;

        b = dq.front();
        dq.pop_front();
        query[i][1] = b;

        if (a > b) {
            dq.push_front(a);
            dq.push_back(b);
        } else {
            dq.push_front(b);
            dq.push_back(a);
        }
    }

    while (!dq.empty()) {
        int f = dq.front();
        dq.pop_front();
        v.push_back(f);
    }

    while (q--) {
        ll m;
        scanf(" %lld", &m);
        m--;

        if (m < ll(n - 1)) {
            printf("%d %d\n", query[m][0], query[m][1]);
        } else {
            m %= ll(n - 1);
            printf("%d %d\n", v[0], v[m + 1]);
        }
    }
}

