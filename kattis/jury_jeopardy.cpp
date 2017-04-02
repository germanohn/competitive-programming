#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 205;

int t;
int freq[10], best[10];
string s;
char ans[N][N];
// North: 0, East: 1, Down: 2, West: 3

int mod(int x) {
    return (x + 4) % 4;
}

void update() {
    for (int i = 0; i < 4; i++) {
        int j = mod(i + 2);
        best[i] = max(best[i], freq[i] - freq[j]);
    }
}

void clear(int h, int w) {
    for (int i = 0; i < 5; i++)
        freq[i] = best[i] = 0;
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) 
            ans[i][j] = '#';
}

int main() {
    scanf(" %d", &t);
    printf("%d\n", t);
    while (t--) {
        clear(100, 100);
        cin >> s;
        int dir = 1;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == 'R') {
                dir = mod(dir + 1);
            } else if (s[i] == 'L') {
                dir = mod(dir - 1);
            } else if (s[i] == 'B') {
                dir = mod(dir + 2);
            }
            update();
        }

        pii cur = pii(1 + best[0], 0);

        ans[cur.ff][cur.ss] = '.';
        dir = 1;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == 'R') {
                dir = mod(dir + 1);
            } else if (s[i] == 'L') {
                dir = mod(dir - 1);
            } else if (s[i] == 'B') {
                dir = mod(dir + 2);
            }
            if (!dir) cur.ff--;
            else if (dir == 1) cur.ss++;
            else if (dir == 2) cur.ff++;
            else cur.ss--;
            ans[cur.ff][cur.ss] = '.';
        }

        int h, w;
        h = w = 0;
        for (int i = 1; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (ans[i][j] == '.') {
                    h = max(h, i + 2);
                    w = max(w, j + 2);    
                }
            }
        }

        printf("%d %d\n", h, w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) 
                printf("%c", ans[i][j]);
            printf("\n");
        }
    }
}
