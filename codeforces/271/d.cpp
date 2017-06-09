#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1500 + 5;

int k, cont, ans;
bool mark[N * N];
char s[N], t[30];
int trie[N * N][30];

void go(int l) {
    int no = 0;
    int bad = 0;
    for (int i = l; s[i] != 0; i++) {
        int nx = s[i] - 'a';
        if (!trie[no][nx]) 
            trie[no][nx] = ++cont;
        no = trie[no][nx];

        if (t[nx] == '0')
            bad++;

        if (bad <= k && !mark[no]) {
            mark[no] = true;
            ans++;
        }
    }
}

int main () {
    scanf(" %s %s %d", s, t, &k);
    for (int i = 0; s[i] != 0; i++) 
        go(i);

    printf("%d\n", ans);
}

