#include <bits/stdc++.h>

using namespace std;

char w[15], x[15], size;
long long int ans;

long long int solve (int i, int f) {
    if (f < 0) {
        return 0;
    }
    if (i == size) {
        if (f == 0)
            return 0;
        else
            return 1;
    }

    else if (w[i] != '?' && f == 0) {
        if (w[i] - '0' > x[i] - '0') {
            return solve (i + 1, 1);
        }
        else if (w[i] - '0' == x[i] - '0')
            return solve (i + 1, 0);
        else if (w[i] - '0' < x[i] - '0')
            return solve (i + 1, -1);
    }
    
    else if (w[i] != '?' && f > 0)
        return solve (i + 1, 1);

    else if (w[i] == '?' && f > 0) { 
        //printf ("? f maior\n");
        return 10*solve (i + 1, 1);
    }

    else if (w[i] == '?' && f == 0) {
      //  printf ("? e empatado\n"); 
        return solve (i + 1, 0) + (10-(x[i]-'0')-1)*solve (i + 1, 1);   
    }
}

int main () {
    while (scanf ("%s %s", w, x) && w[0] != '#') {
        size = strlen (w);
        ans = solve (0, 0);
        printf ("%lld\n", ans);
    }
}
