#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;

int main () {
    scanf("%d %d", &k, &n);
    k = k % 10;
    int ans = 1;
    while (((k * ans) % 10) != n && ((k * ans) % 10) != 0)
       ans++; 
    printf("%d\n", ans);
}

