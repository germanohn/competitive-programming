#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3e4 + 5;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int find_k(int a, int b, bool f) {
    //printf("find_k a %d b %d\n", a, b);
    if (!f) {
        if (b % a == 0) {
            return b / a;
        } else {
            if (a * b > 0) 
                return b / a + 1;
            return b / a;
        }
    } else {
        if (b % a == 0) {
            return b / a + 1;
        } else {
            if (a * b < 0)
                return b / a;
            return b / a + 1;
        }
    }
}

int main() {
    int n, t, _case = 1;
    while (scanf(" %d %d", &n, &t) && (n != 0 || t != 0)) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            scanf(" %d", &x);
            v.pb(x);
        }
        sort(v.begin(), v.end());
        int a = 0;
        int b = n * n;
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                // seja k o primeiro inteiro maior ou igual a t / v[i]
                int k = find_k(v[i], t, 0);
                // seja j o índice do maior inteiro tal que v[j] * v[i] > t
                int j = (lower_bound(v.begin() + i, v.end(), k) - v.begin()) - 1;
                //printf("v[i] %d k %d i %d j %d\n", v[i], k, i, j);
                printf("i %d j %d ", i, j);
                if (j >= i) {
                    a += (2 * (j - i));
                    a++;
                }
            } else if (v[i] == 0) {
                continue;
                if (t < 0) 
                    a += (2 * (n - i - 1)) + 1;
            } else {    
                continue;
                // seja k o primeiro inteiro maior que t / v[i]
                int k = find_k(v[i], t, 1);
                int j = lower_bound(v.begin() + i, v.end(), k) - v.begin();
                // seja j o índice do menor inteiro maior que t > v[i]
                //printf("v[i] %d k %d i %d j %d\n", v[i], k, i, j);
                a += (i == j);
                if (n > j)
                    a += 2 * (n - j - (i == j));
            }
            printf("v[%d] %d a %d\n", i, v[i], a);
        }
        int d = gcd(a, b);
        printf("Case %d: %d/%d\n", _case++, a / d, b / d);
    }
}

