#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b;

int main () {
    scanf ("%d %d", &a, &b);
    int i = 1;
    while (1) {
        if (a == 1 && b == 1) {
            printf ("%d\n", i-1);
            break;
        }
        if (a < b) {
            a += 1;
            b -= 2;
        } else {
            b += 1; 
            a -= 2;
        }
        if (a <= 0 || b <= 0) {
            printf ("%d\n", i);
            break;
        }
        i++;
    }
}

