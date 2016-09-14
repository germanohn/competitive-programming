#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

int n;
int bottom_x, bottom_y, up_x, up_y, mid;
int ff_bottom_x, ff_bottom_y, ff_up_x, ff_up_y;

void print (int i)  {
    if (i == 0) printf ("? %d %d %d %d\n", bottom_x, bottom_y, mid, up_y);
    else if (i == 1) printf ("? %d %d %d %d\n", bottom_x, bottom_y, up_x, mid); 
    else if (i == 2) printf ("? %d %d %d %d\n", mid, bottom_y, up_x, up_y);
    else printf ("? %d %d %d %d\n", bottom_x, mid, up_x, up_y); 
}

void bb () {
    int qtd, l, r;
    bottom_x = bottom_y = 1;
    up_x = up_y = n;
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) l = bottom_x, r = up_x;
        else l = bottom_y, r = up_y;
        while (l != r) {
            printf ("i %d l %d mid %d r %d\n", i, l, mid, r);
            mid = (l+r+1)/2;
            print (i);
            fflush (stdout);
            scanf ("%d", &qtd);
            if (qtd >= 1) {
                if (i == 1) printf ("l %d mid %d r %d\n", l, mid, r);
                if (i == 2 || i == 3) l = mid;
                else r = mid;
            } else {
                if (i == 2 || i == 3) r = mid-1;
                else l = mid+1;
            }
        }
        if (i == 0) {
            up_x = l;
        } else if (i == 1) {
            up_y = l;
        } else if (i == 2) {
            bottom_x = l;
        } else {
            bottom_y = l;
        } 
    }
    ff_bottom_x = bottom_x, ff_bottom_y = bottom_y, ff_up_x = up_x, ff_up_y = up_y;
    bottom_x = bottom_y = 1;
    up_x = up_y = n;
    // i = 0 (bottom_x), i = 1 (bottom_y), i = (up_x), i = (up_y)
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) l = bottom_x, r = up_x;
        else l = bottom_y, r = up_y;
        while (l != r) {
            mid = (l+r+1)/2;
            print ((i+2) % 4);
            fflush (stdout);
            scanf ("%d", &qtd);
            if (qtd >= 1) {
                if (i == 0 || i == 1) l = mid;
                else r = mid;
            } else {
                if (i == 0 || i == 1) r = mid-1;
                else l = mid+1;
            }
        }
        if (i == 0) {
            bottom_x = l;
        } else if (i == 1) {
            bottom_y = l;
        } else if (i == 2) {
            up_x = l;
        } else {
            up_y = l;
        } 
    }
}

int main () {
    scanf (" %d", &n);
    bb ();
    printf ("! %d %d %d %d %d %d %d %d\n", ff_bottom_x, ff_bottom_y, ff_up_x, ff_up_y, bottom_x, bottom_y, up_x, up_y);
    fflush (stdout);
}

