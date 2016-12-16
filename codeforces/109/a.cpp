#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    scanf(" %d", &n);
    int a, b;
    a = b = 0;
    while (b * 7 < n) b++;
    for (; b >= 0; b--) {
        if (n - 7*b >= 0 && (n - 7*b) % 4 == 0) {
            a = (n - 7*b) / 4;
            break;
        }
    }
    if (a * 4 + b * 7 == n) {
        for (int i = 0; i < a; i++) printf("4");
        for (int i = 0; i < b; i++) printf("7");
        printf("\n");
    } else {
        printf("-1\n");
    }
}

