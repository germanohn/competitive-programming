#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int N, n, ans;
int ult[MAX];
char S[MAX][MAX], s[MAX][MAX], ant[MAX][MAX];

void rotate () {
    int k = 0;
    for (int i = n-1; i >= 0; i--) {
        ult[k] = ant[i][0];
        k++;
    }
    // primeira linha
    for (int j = 0; j < n; j++) {
        s[0][j] = ult[j];
        ult[j] = ant[0][j];
    }
    // ultima coluna
    for (int i = 0; i < n; i++) {
        s[i][n-1] = ult[i];
        ult[i] = ant[i][n-1];
    }
    // ultima linha
    k = 0;
    for (int j = n-1; j >= 0; j--) {
        s[n-1][j] = ult[k];
        ult[k] = ant[n-1][j];
        k++;
    }
    // primeira coluna
    k = 0;
    for (int i = n-1; i >= 0; i--) {
        s[i][0] = ult[k];
        ult[k] = ant[i][0];
        k++;
    }
}

int fit () {
    int cont = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + n <= N && i + n <= N) {
                bool f = true;
                for (int l = 0; f && l < n; l++) {
                    for (int k = 0; f && k < n; k++) {
                        if (S[i+l][j+k] != s[l][k])
                           f = false; 
                    }
                }
                if (f) 
                    cont++;
            }
        }
    }
    return cont;
}

int main () {
    while (scanf ("%d %d", &N, &n) && N != 0 && n != 0) {
        ans = 0;
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                scanf (" %c", &S[i][j]);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                scanf (" %c", &s[i][j]);
        printf ("%d ", fit ());
        for (int i = 0; i < 3; i++) {
            for (int l = 0; l < n; l++)
                for (int k = 0; k < n; k++)
                    ant[l][k] = s[l][k];
            rotate ();
            if (i < 2) printf ("%d ", fit ());
            else printf ("%d\n", fit ());
        }
    }
}

