#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 7e3 + 5;

int n;
int state[2][N]; //2: win, 1: loop, 0: lose
vector<int> v[2];

int main () {
    scanf(" %d", &n);
    
    int k;
    scanf(" %d", &k);
    while (k--) {
        int a;
        scanf(" %d", &a);
        v[0].pb(a);
    }
    sort(v[0].begin(), v[0].end());

    scanf(" %d", &k);
    while (k--) {
        int a;
        scanf(" %d", &a);
        v[1].pb(a);
    }
    sort(v[1].begin(), v[1].end());

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (n - v[i][j] + 1 < 1) 
                break;
            state[i][n - v[i][j] + 1] = true;
        }
    }

    for (int i = n; i >= 2; i--) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; v[j].size(); l++) {
                int prev = i - v[j][l];
                if (prev < 1) 
                    break;
                if (state[j][prev] == 2) 
                    continue;

                if (!state[j ^ 1][i]) 
                    state[j][prev] = 2;
                else if (state[j ^ 1][i] == 1)
                    state[j][prev] = 1;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 2; j <= n; j++) {
            if (state[i][j] == 2) {
                printf("Win ");
            } else if (state[i][j] == 1) {
                printf("Loop ");
            } else {
                printf("Lose ");
            }
        }
        printf("\n");
    }
}

