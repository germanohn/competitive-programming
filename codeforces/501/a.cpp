#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b, c, d;

int main () {
    scanf(" %d %d %d %d", &a, &b, &c, &d);
    int x, y;
    x = max(3 * a / 10, a - (a * c) / 250);
    y = max(3 * b / 10, b - (b * d) / 250);
    if (x > y) printf("Misha\n");
    else if (x < y) printf("Vasya\n");
    else printf("Tie\n");
}

