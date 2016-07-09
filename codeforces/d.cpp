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

const int MAX = 1e6+5;

int n, k;
int v[MAX], freq[MAX];
bool p[MAX];

void sieve () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) {
            for (int j = i*i; j < MAX; j++) 
                p[i] = true;
        }
    }
}

int main () {
    scanf ("%d %d", &n, &k);
    int a;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        v[a]++;
    }
    int aux = k;
    for (int i = 2; i <= aux; i++) {
        while (aux % i == 0) {
            freq[i]++;
            aux /= i;
        }
    }
    bool f = true;
    for (int i = 2; f && i <= k; i++) {
        if (freq[i] != 0) {
            if (v[i] == 0)
               f = false; 
        }
    }
    
    if (f) {
        if (k == 1 && v[1] == 0) 
            printf ("No\n");
        else printf ("Yes\n");
    } else if (!f)  
        printf ("No\n");
    
}

