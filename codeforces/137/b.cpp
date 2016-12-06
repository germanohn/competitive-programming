#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int freq[5005];

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        freq[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= 5000; i++) {
        if (i > n) ans += freq[i];
        else if (freq[i] > 1) ans += (freq[i] - 1);
    }
    printf("%d\n", ans);
}

