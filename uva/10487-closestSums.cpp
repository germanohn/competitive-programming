#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int v[1005], sum[1000005], q[30];

int main () {
    int cont = 1;
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) 
            scanf ("%d", &v[i]);
        sort (v, v+n);
        scanf ("%d", &m);
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                sum[k++] = v[i]+v[j];
            }
        }
        sort (sum, sum+k);
        int num;
        printf ("Case %d:\n", cont++);
        for (int i = 0; i < m; i++) { 
            scanf ("%d", &num); 
            int a = sum[0], j;
            for (j = 1; j < k; j++) {
                if (sum[j] > num) { 
                    if (abs (num-a) < abs (sum[j]-num)) 
                        printf ("Closest sum to %d is %d.\n", num, a);
                    else 
                        printf ("Closest sum to %d is %d.\n", num, sum[j]);
                    break;
                }
                a = sum[j];
            }
            if (j == k) printf ("Closest sum to %d is %d.\n", num, sum[k-1]);
        }
    }
}

