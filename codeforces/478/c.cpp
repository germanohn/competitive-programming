#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll v[3];

int main () {
    scanf(" %lld %lld %lld", &v[0], &v[1], &v[2]);
    sort(v, v + 3);

    if (v[2] <= 2 * (v[0] + v[1])) 
        printf("%lld\n", (v[0] + v[1] + v[2]) / 3);
    else 
        printf("%lld\n", v[0] + v[1]);
}

