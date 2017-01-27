#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int w[10], d[10];

int main () {
    for (int i = 0; i < 4; i++)
        scanf(" %d", w + i);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 52; i++)
        for (int j = i + 1; j <= 52; j++)
            for (int k = j + 1; k <= 52; k++)
                for (int l = k + 1; l <= 52; l++) {
                    int x = 0, c = 1, cur_ans = 0;
                    vector<int> groups[10];
                    groups[0].pb(i);
                    if (j == i + 1) groups[0].pb(j);
                    else groups[c++].pb(j);
                    if (k == j + 1) groups[c-1].pb(k);
                    else groups[c++].pb(k);
                    if (l == k + 1) groups[c-1].pb(l);
                    else groups[c++].pb(l);

                    for (int oi = 0; oi < c; oi++) {
                        int ind;
                        for (ind = 0; ind < 4; ind++)
                            if (w[ind] >= groups[oi][0]) break;
                        cur_ans += ((52 - (4 - ind + x)) * ((int) groups[oi].size()));
                        x += (int) groups[oi].size();
                    }
                    if (cur_ans < ans) {
                        ans = cur_ans;
                        d[0] = i, d[1] = j, d[2] = k, d[3] = l;
                    }
                }
    printf("%d %d %d %d\n", d[0], d[1], d[2], d[3]);
}

