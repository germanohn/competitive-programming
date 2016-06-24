#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int v[105], vsort[105];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf ("%d", &v[i]);
        vsort[i] = v[i];
    }
    sort (vsort, vsort+n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
             if (v[j] == vsort[i]) {
                for (int l = j; l > i; l--) {
                    int tm = v[l-1];
                    v[l-1] = v[l];
                    v[l] = tm;
                    printf ("%d %d\n", l, l+1);
                }   
                break;
             }
        }
    }
}

