#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/////////////////0123456789
const int MAX = 205;

int n;
int acc_u[MAX], acc_d[MAX], acc_r[MAX], acc_l[MAX];
char s[MAX];

int main() {
    scanf (" %d %s", &n, s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'U') {
            acc_u[i+1] = 1;
        } else if (s[i] == 'D') {
            acc_d[i+1] = 1;
        } else if (s[i] == 'L') {
            acc_l[i+1] = 1;
        } else {
            acc_r[i+1] = 1;
        }
        acc_u[i+1] += acc_u[i], acc_d[i+1] += acc_d[i];
        acc_l[i+1] += acc_l[i], acc_r[i+1] += acc_r[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (acc_u[j+1] - acc_u[i] == acc_d[j+1] - acc_d[i]
                && acc_l[j+1] - acc_l[i] == acc_r[j+1] - acc_r[i])
               ans++; 
        }
    }

    printf ("%d\n", ans);
}

