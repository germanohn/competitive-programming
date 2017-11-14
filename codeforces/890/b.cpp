#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n;
int last[N];

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf(" %d", &a);
        last[a] = i;
    }

    int last_visit = N;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (last[i] && last[i] < last_visit) { 
            last_visit = last[i];
            ans = i;
        }
    }

    printf("%d\n", ans);
}

