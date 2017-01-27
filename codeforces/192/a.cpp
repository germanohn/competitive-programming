#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main () {
    scanf(" %d", &n);
    int mid = sqrt(n);
    for (int i = 1; i <= mid; i++) {
        int aux = n - (i * (i + 1) / 2);
        int left = sqrt(2 * aux);
        if (aux && left * (left + 1) == 2 * aux) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}

