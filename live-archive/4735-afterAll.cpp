#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int a, b;
int f1[MAX], f2[MAX], p[MAX];

// guarda o maior primo que divide p[i]
void sieve () {
    p[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) 
            for (int j = i; j < MAX; j += i) 
                p[j] = i;
    }
}

void factor (int x, int kind) {
    while (x > 1) {
        if (kind == 1) f1[p[x]]++;
        else f2[p[x]]++;
        x /= p[x];
    }
}

int main () {
    sieve ();
    int t = 1;
    while (scanf ("%d %d", &a, &b) && a != 0 && b != 0) {
        for (int i = 0; i < MAX; i++) {
            f1[i] = f2[i] = 0;
        }
        factor (a, 1);
        factor (b, 2);
        int ma = max (a, b), dim = 0, dis = 0;
        for (int i = 2; i <= ma; i++) {
            if (f1[i] != 0 || f2[i] != 0) 
                dim++;
            dis += abs (f1[i] - f2[i]);
        }
        printf ("%d. %d:%d\n", t++, dim, dis);
    }
}



