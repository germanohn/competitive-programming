#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 30;

stack<tuple<int, int, int> > s[N];

int main () {
    int n;
    scanf(" %d", &n);
    char c;
    scanf("%c", &c);
    int row = 1, col = 0, scope = 0;
    while (scanf("%c", &c) != EOF) {
        col++;
        if (c == '\n') {
            row++;
            col = 0;
        } else if (c == '{') {
            scope++;
        } else if (c >= 'a' && c <= 'z') {
            int l = c - 'a';
            if (!s[l].empty()) {
                printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", 
                       row, col, c, get<0>(s[l].top()), get<1>(s[l].top()));
            }
            s[l].push(mt(row, col, scope));

        } else if (c == '}') {
            for (int i = 0; i < 26; i++) {
                if (!s[i].empty()) {
                    if (get<2>(s[i].top()) == scope)
                        s[i].pop();
                }
            }
            scope--;
        }
    }
}

