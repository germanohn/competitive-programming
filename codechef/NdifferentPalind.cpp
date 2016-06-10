#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 100005;

int n, t;
int acc[MAX];

int main () {
    acc[1] = 1;
    for (int i = 2; i <= 3000; i++) {
        acc[i] = acc[i-1]+i;
    }
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        char c = 'a';
        while (n > 0) {
            int lo = 1, hi = 3000;
            while (lo != hi) {
                int mid = (lo + hi)/2;
                if (acc[mid] > n) 
                    hi = mid;
                else 
                    lo = mid+1; 
            }
            lo--;
            n -= acc[lo];
            for (int i = 0; i < lo; i++) 
                printf ("%c", c);
            c++;
        }
        printf ("\n");
    }
}
