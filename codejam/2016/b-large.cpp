#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;

void flip (char* s, int r) {
    for (int i = 0; i <= r; i++) {
        if (s[i] == '+')
            s[i] = '-';
        else 
            s[i] = '+';
    }
}

bool verify (char* s) {
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '-')
            return false;
    }
    return true;
}

int main () {   
    scanf ("%d", &t);
    int test = 1;
    while (t--) {
        char s[105];
        int ans = 0;
        scanf (" %s", s);
        char c = s[0];
        printf ("Case #%d: ", test++);
        int i = 1;
        while (!verify (s)) {
            if (s[i] != c) { 
                flip (s, i-1);
                c = s[0];
                i = 1;
                ans++;
            } else {
                if (s[i+1] == 0) { 
                    ans++;
                    break;
                }
                i++;
            }
        }
        printf ("%d\n", ans);
    }
}

