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

        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
    }

    while (!dq.empty()) {
        v.push_back(dq.front());
        dq.pop_front();
    }

    while (q--) {
        ll m;
        scanf(" %lld", &m);
        m--;

        if (m < n - 1) {
            printf("%d %d\n", query[m][0], query[m][1]);
        } else {
            m %= n - 1;
            printf("%d %d\n", v[0], v[m + 1]);
        }
    }
}

