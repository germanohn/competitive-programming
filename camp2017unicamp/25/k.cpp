#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
pii cur, guess; // row, col
int freq[5], best[5]; // U, D, L, R

bool valid(int row, int col) {
    if (row - best[0] <= 0 || row + best[1] > n || 
        col - best[2] <= 0 || col + best[3] > m)
        return false;
    return true;
}

void next_init() {
    cur.ss++;
    if (cur.ss == m + 1) 
        cur.ff++, cur.ss = 1;
}

pii next_guess() {
    pii cand = cur;
    while (!valid(cand.ff, cand.ss)) {
        next_init();
        cand = cur;
    }
    next_init();
    return pii(cand.ff + (freq[1] - freq[0]), cand.ss + (freq[3] - freq[2]));;
}

void update() {
    for (int i = 0; i < 4; i++) 
        best[i] = max(best[i], freq[i] - freq[i ^ 1]);
}

int val(char c) {
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'L') return 2;
    return 3;
}

int main () {
    scanf(" %d %d", &n, &m);

    cur = pii(1, 1);
    guess = cur;
    next_init();
    while (true) {
        printf("%d %d\n", guess.ff, guess.ss);
        fflush(stdout);

        char s[15];
        scanf(" %s", s);
        if (s[0] == 'D' && s[1] == 'E')
            break;
        freq[val(s[0])]++;
        update();

        guess = next_guess();
    }
    fflush(stdout);
    return 0;
}

