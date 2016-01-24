#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int c, n, v[1005];
map<int, set<int> > m;


int mdc (int a, int b) {
    if (a % b == 0) return b;
    return mdc (b, a % b); 
}

int main () {
    scanf ("%d", &c);
    int tmp, tam = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            tmp = mdc (i, j);
            int x = i, y = j;
            x /= tmp;
            y /= tmp;
            //                printf ("i %d j %d mdc %d\n", i, j, tmp);
            if (m[x].find (y) != m[x].end ()) {
                //printf ("ja esta i %d j %d\n", i, j);
                continue;
            }
            else {
                //printf ("i %d j %d mdc %d\n", i, j, tmp);
                m[x].insert (y);
                tam++;
            }
        }
        v[i] = 2*tam + 1; 
    }
    int cont = 1;
    while (c--) {
        scanf ("%d", &n);
        n++;
        printf ("%d %d %d\n", cont++, n-1, v[n-1]);
    }
}
