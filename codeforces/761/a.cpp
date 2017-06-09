#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int a, b;
    scanf(" %d %d", &a, &b);
    if (abs(a - b) > 1 || (a == 0 && b == 0)) printf("NO\n");
    else printf("YES\n");
}

