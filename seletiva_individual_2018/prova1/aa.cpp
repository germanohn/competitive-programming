#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3e4 + 5;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int main() {
    int n, t, _case = 1;
    while (scanf(" %d %d", &n, &t) && (n != 0 || t != 0)) {
        vector<int> neg, pos;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf(" %d", &x);
            if (x < 0) neg.pb(x);
            else if (!x) zeros++;
            else pos.pb(x);
        }
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        int a = 0;
        int b = n * n;
        if (t > 0) {
            int l, r;
            if (neg.size()) {
                // pares de negativos
                l = 0, r = neg.size() - 1;
                while (l < r) {
                    if (neg[l] * neg[r] > t) {
                        a += 2 * (r - l) + 1;
                        l++;
                    } else {
                        r--;
                    }
                }
                if (neg[l] * neg[l] > t)
                    a++;
            } 

            if (pos.size()) {
                // pares de positivos
                for (l = 0, r = pos.size() - 1; l < (int)pos.size() && r > l; l++) {
                    if (pos[l] * pos[l] > t)
                        a++;
                    while (r > l && pos[l] * pos[r] > t)
                        r--;
                    a += 2 * ((pos.size() - 1) - r);
                }
                a += (pos.size() - l) * (pos.size() - l) * ((pos[l] * pos[l]) > t);
            }
        } else if (t == 0) {
            // pares de negativos entre si
            a += neg.size() * neg.size();
            // pares de positivos
            a += pos.size() * pos.size();
        } else {
            // pares de negativos entre si
            a += neg.size() * neg.size();
            // pares de zeros, e de zero com outro número qualquer não zero
            a += zeros + zeros * 2 * (neg.size() + pos.size());
            // pares de positivos
            a += pos.size() * pos.size();
            if (neg.size() && pos.size()) {
                // pares de negativos com positivos
                int j = 0;
                for (int i = 0; i < (int)neg.size(); i++) {
                    while (j < (int)pos.size() && neg[i] * pos[j] > t)
                        j++;
                    a += 2 * j;
                }
            }
        }
        printf("a %d ", a);
        int d = gcd(a, b);
        printf("Case %d: %d/%d\n", _case++, a / d, b / d);
    }
}

