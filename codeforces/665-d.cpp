#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2000005;

int n;
bool p[MAX];
vector<int> par, im;

void sieve () {
    for (int i = 2; i*i < MAX; i++) {
        if (!p[i]) 
            for (int j = i*i; j < MAX; j += i)
                p[j] = true;
    }
}

int main () {
    scanf ("%d", &n);
    sieve ();
    int um = 0, a;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        if (a % 2 == 0) {
            par.pb (a);
        } else {
            im.pb (a);
            if (a == 1)
                um++;
        }
    }
    sort (par.begin (), par.end ());
    sort (im.begin (), im.end ());
    if (um >= 2) {
        int num_par = -1;
        for (int i = 0; i < par.size (); i++) {
            if (!p[par[i]+1]) {
                num_par = par[i];
                break;
            }
        }
        if (num_par != -1) {
            printf ("%d\n", um+1);
            for (int i = 0; i < um; i++) 
                printf ("1 ");
            printf ("%d\n", num_par);
        } else {
            printf ("%d\n", um);
            for (int i = 0; i < um; i++) 
                printf ("1 ");
            printf ("\n");
        }
    } else {
        for (int i = 0; i < im.size (); i++) {
            int num = im[i];
            for (int j = 0; j < par.size (); j++) {
                if (!p[(num+par[j])]) {
                    printf ("2\n");
                    printf ("%d %d\n", num, par[j]);
                    return 0;
                }                   
            }
        }
        printf ("1\n");
        if (par.size () != 0) 
            printf ("%d\n", par[0]);
        else 
            printf ("%d\n", im[0]);
    }
}

