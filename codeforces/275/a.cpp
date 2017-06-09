#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cur[3][3];

int main () {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            cur[i][j] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            scanf(" %d", &a);
            if (!a) continue;
            cur[i][j] += a;
            for (int l = 0; l < 4; l++) {
                int x, y;
                x = i + dx[l], y = j + dy[l];
                if (x >= 0 && x < 3 && y >= 0 && y < 3) 
                    cur[x][y] += a;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (cur[i][j] % 2 == 0) 
                printf("0");
            else 
                printf("1");
        }
        printf("\n");
    }
}

