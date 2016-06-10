#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int a, b, c;
    bool f = false;
    scanf ("%d %d %d", &a, &b, &c);
    if (c < 0) {
        c *= -1;
        if (b-a <= 0) {
            if ((a-b) % c == 0) {
                f = true;
            } else {
                f = false;
            }
        } else {
            f = false;
        }
    } else if (c == 0) {
        if (b == a) 
            f = true;
        else 
            f = false;
    } else {
        if (b-a < 0) {
            f = false;
        } else {
            if ((b-a) % c == 0) {
                f = true;
            } else {
                f = false;
            }
        }
    }
    
    if (f) 
        printf ("YES\n");
    else 
        printf ("NO\n");
}

