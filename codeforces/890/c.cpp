#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

bool out[N];

int main() {
    int n;
    scanf(" %d", &n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int tempo;
        scanf(" %d", &tempo);
        if (out[tempo]) 
            ans++;
        out[tempo] = true;
    }

    printf("%d\n", ans);
}

