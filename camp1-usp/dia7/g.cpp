#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 50000;

int n;
int v[MAX];

void separa (int l, int r) {
    int m = (l+r)/2, aux[MAX];
    int ini = l, fim = r;
    for (int i = l; i <= r; i++) {
        if (v[i] > m) {
            aux[fim--] = v[i];
            printf ("%d ", v[i]);
        } else {
            aux[ini++] = v[i];
            printf ("%d %d ", v[i], v[i]);
        }
    }
    for (int i = l; i <= r; i++) v[i] = aux[i];
    for (int i = m+1; i <= r; i++) printf ("%d ", v[i]);
}

void quicksort (int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        separa (l, r);
        quicksort (l, m);
        quicksort (m+1, r);
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= (1 << n); i++) 
        scanf ("%d", &v[i]);
    quicksort (1, (1 << n));
    printf ("\n");
}

