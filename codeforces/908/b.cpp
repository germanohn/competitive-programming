#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;

int n, m;
char maze[N][N];

bool can(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#')
        return true;
    return false;
}

int main() {
    scanf(" %d %d", &n, &m);
    int st[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'S') 
                st[0] = i, st[1] = j;
        }
    }
    string s;
    cin >> s;
    int dir[4] = {0, 1, 2, 3};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int cont = 0;
    do {
        bool found = false;
        int cur[2];
        cur[0] = st[0], cur[1] = st[1];
        for (int i = 0; !found && s[i] != 0; i++) {
            int inst = s[i] - '0';
            int nx[2];
            nx[0] = cur[0] + dx[dir[inst]], nx[1] = cur[1] + dy[dir[inst]];
            if (can(nx[0], nx[1])) {
                if (maze[nx[0]][nx[1]] == 'E')
                    found = true;
                cur[0] = nx[0], cur[1] = nx[1];
            } else {
                break;
            }
        }
        if (found) 
            cont++;
    } while (next_permutation(dir, dir + 4));
    printf("%d\n", cont);
}

