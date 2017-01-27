#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, m;
int city[MAX], tower[MAX];

int main() {
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &city[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf(" %d", &tower[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        a = lower_bound(tower, tower + m, city[i]) - tower;
        
        int tmp = INT_MAX;
        if (a != m) tmp = abs(tower[a] - city[i]);
        if (a > 0)  
            tmp = min(tmp, abs(city[i] - tower[a - 1]));

        ans = max(ans, tmp);
    }   

    printf("%d\n", ans);
}
