#include <bits/stdc++.h>
using namespace std;

int n, t;
char num[105];

int main () {
    scanf ("%d %d", &n, &t);
    int pot = 1;
    if (t/10 == n)
        printf ("-1\n");
    else {
        if (t/10 == 1) 
            num[0] = '1';
        else 
            num[0] = t + '0';
        for (int i = 1; i < n; i++)
            num[i] = '0';
        printf ("%s\n", num);
    }
}
