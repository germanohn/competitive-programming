#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n;
int p[MAX * MAX];

void sieve() {
    for (int i = 2; i < MAX * MAX; i++) {
        if (!p[i])
            for (int j = i; j < MAX * MAX; j += i) 
                p[j] = i;
    }
}

int main () {
    sieve();
    scanf(" %d", &n);
    for (int m = 1; m <= 1000; m++) {
        int aux = m * n + 1;
        int cont = 0;
        while (aux > 1) {
            aux /= p[aux];
            cont++; 
        }
        if (cont > 1) {
            printf("%d\n", m);
            break;
        }
    }
}

