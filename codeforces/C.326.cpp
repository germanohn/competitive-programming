#include <bits/stdc++.h>
#define MAX 1000050

using namespace std;

int n, ans, freq[MAX], a;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < MAX; i++) 
        freq[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        freq[a]++;
    } 
    for (int i = 0; i < MAX; i++) {
        freq[i+1] += freq[i]/2;
        freq[i] %= 2;
        if (freq[i] == 1)
            ans++;
    }
    printf ("%d\n", ans);
}
