#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2005;

int n, v[MAX], ans[MAX];

int gdc (int a, int b) {
    if (a%b == 0) return b;
    return gdc (b, a%b);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    if (n == 1) {
        printf ("0\n%d\n", v[0]);
        return 0;
    }
    ans[0] = v[0];
    int cont = 0, k = 1;
    for (int i = 1; i < n; i++) {
        if (gdc (v[i], v[i-1]) != 1) 
            ans[k++] = 1, ans[k++] = v[i], cont++;
        else 
            ans[k++] = v[i];
    }
    printf ("%d\n", cont);
    for (int i = 0; i < k; i++) 
        printf ("%d ", ans[i]);
    printf ("\n");
}
