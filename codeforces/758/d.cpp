#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 65;

int n, len;
char k[MAX];

ll dp(int i) {
    if (i == len) return 0;
    if (me[i] != -1) return me[i];

}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %s", &n, k);
    int len = strlen(k);
    printf("%lld\n", dp(0));
}

