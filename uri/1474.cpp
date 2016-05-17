#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct matrix {
    ll M[2][2];
};
    
const ll MOD = 1e6;

ll n, m, o;
matrix I = { {1, 0}, {0, 1} };
char rta[10];

matrix mul (matrix B, matrix C) {
    matrix A;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A.M[i][j] = 0;
            for (int l = 0; l < 2; l++) {
                A.M[i][j] += (B.M[i][l] * C.M[l][j]) % MOD; 
            }
            A.M[i][j] %= MOD;
        }
    }
    return A;
}
/*
matrix fexp (matrix M, ll exp) {
    if (exp == 0) return I;
    if (exp == 1) return M;
    if (exp % 2 == 0) { 
        return fexp (mul (M, M), exp/2); 
    }
    return mul (M, fexp (mul (M, M), exp/2));
}
*/
matrix fexp (matrix y, ll exp) {
    matrix x = I;
    while (exp > 0) {
        if (exp % 2 == 1) 
            x = mul (x, y);
        y = mul (y, y);
        exp /= 2;
    }
    return x;
} 

int solveLinearRecorrence (ll i) {
    // i é a posicao do elemento na recorrencia, no caso os casos bases
    // serao f (5) que chamo com i = 0 e f (10) que chamo com i = 1
    if (i == 0) {
        return m % MOD;
    } else if (i == 1) {
        return (m*m + o) % MOD;
    } 
    matrix T = {m, o, 1, 0};
    T = fexp (T, i-1);

    ll ans;
    ans = (T.M[0][0]) * ((m*m) % MOD + o) + (T.M[0][1] * m) % MOD;
    ans %= MOD;
    return ans;
}

int main () {
    while (scanf ("%lld %lld %lld", &n, &m, &o) != EOF) {
        m %= MOD, o %= MOD;
        ll exp = n/5 - 1;
        int ans = solveLinearRecorrence (exp);
        sprintf (rta, "%d", ans);
        int tam = strlen (rta);
        for (int i = 0; i + tam < 6; i++) 
            printf ("0");
        printf ("%d\n", ans);
    }
}

