#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
/*
int size, pos;

int main () {
    while (scanf ("%d %d", &size, &pos) && size != 0 && pos != 0) {
        int x, y, sum;
        x = y = (size+1)/2, sum = 1;
        for (int i = 1; sum < pos; i++) {
            if (i % 2 != 0) {
                // andar pra cima
                if (sum + i <= pos) {
                    y += i;
                    sum += i;
                } else if (sum < pos) {
                    y += pos - sum;
                    sum = pos;
                }
                // andar pra esquerda
                if (sum + i <= pos) {
                    x -= i;
                    sum += i;
                } else if (sum < pos) {
                    x -= pos - sum;
                    sum = pos;
                }
            } else {
                // andar pra baixo
                if (sum + i <= pos) {
                    y -= i;
                    sum += i;
                } else if (sum < pos) {
                    y -= pos - sum;
                    sum = pos;    
                }
                // andar pra direita
                if (sum + i <= pos) {
                    x += i;
                    sum += i;
                } else if (sum < pos) {
                    x += pos - sum;
                    sum = pos;
                }
            }
        }
        printf ("Line = %d, column = %d.\n", y, x);
    }
}
*/

int size, pos;

inline ll f (ll n) {
    return 3 + 2*(n-1)*(n+3);
}

int main () {
    while (scanf ("%d %d", &size, &pos) && size != 0 && pos != 0) {
        if (pos == 1) {
            printf ("Line = %d, column = %d.\n", (size+1)/2, (size+1)/2);
            continue;
        } else if (pos == 2) {
            printf ("Line = %d, column = %d.\n", (size+1)/2, (size+1)/2 + 1);
            continue;
        }
        ll l = 1, r = 110000, m;
        while (1) {
            m = (l+r+1)/2;
//            printf ("f (m) %d\n", f (m));
            if (f (m) <= pos && f (m+1) > pos) {
                break;
            } else if (f (m) < pos) {
                l = m-1;
            } else {
                r = m-1;
            }
        }
        pos = pos - f (m);
        int x = ((size + 1)/2 - m);
        int y = ((size + 1)/2 + m);
        if (pos <= m+1) {
            y -= pos;
        } else if (pos <= 2*(m+1)) {
            y -= m+1;
            pos -= m+1;
            x += pos;           
        } else if (pos <= 2*(m+1) + m+2) {
            y -= m+1;
            x += m+1;
            pos -= 2*(m+1);
            y += pos;
        } else {
            y++;
            x += m+1;
            pos -= 2*(m+1) + m+2;
            x -= pos;
        }
        printf ("Line = %d, column = %d.\n", y, x);
    }
}
