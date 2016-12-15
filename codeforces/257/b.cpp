#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, m;
    scanf(" %d %d", &n, &m);
    if (n < m) swap(n, m);
    printf("%d %d\n", n - 1, m);
}

