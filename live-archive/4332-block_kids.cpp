#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e4 + 7;

struct matrix {
    ll M[4][4];
};

matrix I = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

ll mod(ll x) {
    return (x + MOD) % MOD;
}

matrix mult(matrix A, matrix B) {
    matrix C;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            C.M[i][j] = 0;
            for (int k = 0; k < 4; k++) 
                C.M[i][j] = mod(C.M[i][j] + mod(A.M[i][k] * B.M[k][j]));
        }
    }
    return C;
}

matrix fexp(matrix A, int e) {
    matrix X = I;
    while (e > 0) {
        if (e & 1) 
            X = mult(X, A);
        A = mult(A, A);
        e /= 2;
    }
    return X;
}

ll number_ways(int n) {
    if (n == 0) return 1;
    if (n == 1) return 4;
    matrix T = {2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 0};
    T = fexp(T, n - 1);
    ll A[4] = {4, 1, 2, 1};
    ll ans = 0;
    for (int i = 0; i < 4; i++) 
        ans = mod(ans + mod(T.M[0][i] * A[i]));
    return ans;
}

int main() {
    int n;
    while (scanf(" %d", &n)) {
        if (n == -1) break;
        printf("%lld\n", number_ways(n));
    }
}

