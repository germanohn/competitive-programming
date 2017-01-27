#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    int q = a;
    q = min(q, b/2);
    q = min(q, c/4);
    printf("%d\n", q*1 + q*2 + q*4);
}

