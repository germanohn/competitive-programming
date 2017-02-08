#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b, c, d;

int gcd(int x, int y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

int main () {
    scanf(" %d %d %d %d", &a, &b, &c, &d);
    int num, den;
    if (b * c < a * d) {
        num = (a * d) - (b * c);
        den = a * d;
        int div = gcd(num, den);
        num /= div, den /= div;
        printf("%d/%d\n", num, den);
    } else if (b * c == a * d) {
        printf("0/1\n");
    } else {
        num = (b * c) - (a * d);
        den = b * c;
        int div = gcd(num, den);
        num /= div, den /= div;
        printf("%d/%d\n", num, den);
    }
}

