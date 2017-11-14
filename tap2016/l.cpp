#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool in_range(int x, int ref) {
    if (x < ref - 2 || x > ref + 2 || x == ref) return false;
    return true;
}

int main() {
    int n, k;
    int light[N];
    while (scanf(" %d %d", &n, &k) != EOF) {
        for (int i = 0; i < k; i++) {
            scanf(" %d", &light[i]);
        }

        bool ok = true;
        for (int i = 1; ok && i < k - 1; i++) {
            int pre = light[i - 1];
            int cur = light[i];
            int nxt = light[i + 1];
            if (!in_range(pre, cur) || !in_range(nxt, cur)) {
                ok = false;
            } else if (pre == nxt || (pre > cur && nxt > cur)) {
                ok = false;
            } else if (cur == 1 || cur == 2) {
                ok = false;
            }
        }
        if (k == 2) {
            int a, b;
            a = light[0], b = light[1];
            if (a == b || abs(a - b) > 2 || (a == 1 && b == 2) || (a == 2 && b == 1))
                ok = false;
        } else if (k > 2) {
            int a, b;
            a = light[0], b = light[1];
            if (a == b || abs(a - b) > 2)
                ok = false;
            a = light[k - 2], b = light[k - 1];
            if (a == b || abs(a - b) > 2)
                ok = false;
        }

        if (!ok) printf("N\n");
        else printf("S\n");
    }
}

