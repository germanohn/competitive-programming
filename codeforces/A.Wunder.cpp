#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 20; i >= 0; i--) {
        if ((1<<i) <= n) {
            n -= 1<<i;
            printf ("%d ", i+1); 
        }
    }
    printf ("\n");
}
