#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int A[5][5], B[5][5];
int k_a, k_b;
char a[5], b[5];

int main() {
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) 
            scanf (" %c", &A[i][j]);

    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) 
            scanf (" %c", &B[i][j]);

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            for (int j = 0; j < 2; j++) 
                if (A[i][j] != 'X')
                    a[k_a++] = A[i][j];
        } else {
            for (int j = 1; j >= 0; j--) 
                if (A[i][j] != 'X')
                    a[k_a++] = A[i][j];
        }
    }      

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            for (int j = 0; j < 2; j++) 
                if (B[i][j] != 'X')
                    b[k_b++] = B[i][j];
        } else {
            for (int j = 1; j >= 0; j--) 
                if (B[i][j] != 'X')
                    b[k_b++] = B[i][j];
        }
    }      

    bool f = false;
    for (int i = 0; !f && i < 3; i++) {
        f = true;
        for (int j = 0; f && j < 3; j++) {
            if (a[j] != b[(i+j) % 3]) 
                f = false;
        }
    }   
    if (f) printf ("YES\n");
    else printf ("NO\n");
}

