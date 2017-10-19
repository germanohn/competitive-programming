#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    for (int i = 0; i < 5; i++) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return true;
}

int main() {
    int t, n, test = 1;
    scanf(" %d", &t);
    while (t--) {
        printf("Case #%d:\n", test++);
        scanf(" %d", &n);
        vector<vector<int> > team(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                int a;
                scanf(" %d", &a);
                team[i].pb(a);
            }
            sort(team[i].begin(), team[i].end(), greater<int>());
        }

        sort(team.begin(), team.end(), cmp);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) 
                printf("%d%c", team[i][j], j < 4 ? ' ' : '\n');
        }
    }
}

