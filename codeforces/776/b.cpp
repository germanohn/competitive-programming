#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int p[N];

void sieve() {
    p[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (!p[i]) 
            for (int j = i * i; j < N; j += i)
                p[j] = true;
    }
}

int main () {
    scanf(" %d", &n);
    sieve();
    if (n <= 2) printf("1\n");
    else printf("2\n");
    for (int i = 2; i <= n + 1; i++) {
        if (!p[i]) 
            printf("1 ");
        else 
            printf("2 ");
    }
    printf("\n");
}

