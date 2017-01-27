#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, a, b;
    a = b = 0;
    scanf(" %d", &n);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        if (x % 2 == 1) {
            if (a % 2 == 1) 
                a += x, b += y;
            else 
                a += y, b += x, cont++;
        } else if (y % 2 == 1) {
            if (a % 2 == 1) 
                a += y, b += x, cont++;
            else 
                a += x, b += y;
        }
    }
    if (a % 2 == 0 && b % 2 == 0) 
        printf("
}

