#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int MAXN = 105;
const int MAXL = 1005;
const int ALF = 'z' - 'a' + 1;

int cnt[ALF], quant, n;
char A[MAXN][MAXL];
int tam[MAXN], val[MAXN];;
vector<int> v[MAXN];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %s", A[i]);
        tam[i] = strlen (A[i]);
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < tam[i]; j++) {
            cnt[A[i][j]-'a']++;
        }
        quant = 0;
        for (int j = 0; j < ALF; j++) {
            if (cnt[j] != 0) {
                quant++;
            }
        }
        if (quant <= 2) {
            val[i] = 1;
            for (int j = 0; j < ALF; j++) {
                if (cnt[j] != 0) 
                    v[i].pb (j + 'a');           
            }    
        }
        else {
            val[i] = 0;            
        }  
    }
    int t = 0, maxi = 0;
    for (int i = 0; i < ALF; i++) {
        for (int j = i + 1; j < ALF; j++) {
            t = 0;
            for (int l = 0; l < n; l++) {
                if (val[l]) {
                    if (v[l].size () == 1) {
                        if (v[l][0] == i+'a' || v[l][0] == j+'a') {
                            t += tam[l];   
                        }
                    }
                    else {
                        if (v[l][0] == i+'a' && v[l][1] == j+'a') {
                            t += tam[l];
                        }
                    }
                }
            }
            if (t > maxi)
                maxi = t;
        }
    }
    printf ("%d\n", maxi);
}
