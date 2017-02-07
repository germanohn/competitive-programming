#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n;
int pi[MAX], z[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &z[i]);
    for (int i = 2; i <= n; i++) {
        pi[i] = pi[i - 1];
        while (pi[i] > 0 && z[i - 1 - pi[i]] <= pi[i]) 
            pi[i] = pi[pi[i]];
        if (z[i - 1 - pi[i]] > pi[i])
            pi[i]++;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", pi[i]);
    printf("\n");
}

