#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, cont, a, median;
vector<int> v;

int main () {
    while (scanf ("%d", &a) != EOF) {
        v.pb (a);
        cont++;
        if (cont % 2 == 0) {
            nth_element (v.begin (), v.begin () + cont/2, v.end ());
            median = v[cont/2];
            nth_element (v.begin (), v.begin () + cont/2 -1, v.end ());
            median += v[cont/2-1];
            median /= 2;
            printf ("%d\n", median);    
        } else {
            nth_element (v.begin (), v.begin () + cont/2, v.end ());
            median = v[cont/2];
            printf ("%d\n", median);
        }
    }
}

