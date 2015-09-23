#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, k, a, b, v[MAX];
pair <int, int> bit[MAX];

void update (int idx, int val, int flag) {
    for (int i = idx; i <= n; i += i & -i)
            if(flag) bit[i].first += val;   
            else bit[i].second += val;
}

pair<int, int>  query (int idx) {
    pair<int, int> sum; 
    for (int i = idx; i > 0; i -= i & -i) {
        sum.first += bit[i].first;
        sum.second += bit[i].second;
    }
    return sum;    
}

int main () {
    int v[MAX];
    while (scanf ("%d %d", &n, &k) != EOF) {
        for (int i = 0; i <= n; i++) {
            bit[i].first = 0;
            bit[i].second = 0;
        }
            
        for (int i = 1; i <= n; i++) { 
            scanf ("%d", &v[i]);
            if(v[i] == 0) update (i, 1, 0);
            else if (v[i] < 0) update (i, 1, 1);
        }
        char c;
        for (int i = 0; i < k; i++) {
            scanf (" %c %d %d", &c, &a, &b);
            if (c == 'C') {
                if (v[a] == 0) update (a, -1, 0);
                else if (v[a] < 0) update (a, -1, 1);
                v[a] = b;
                if (v[a] == 0) update (a, 1, 0);
                else if (v[a] < 0) update (a, 1, 1);
            }  
            else {
                   
                pair<int, int> fim;
                pair<int, int> ini;
                fim = query (b);
                ini = query (a - 1);
                if (fim.second - ini.second == 0) {
                    if ((fim.first - ini.first) % 2 != 0)
                        printf ("-");
                    else
                        printf ("+");
                }
                else
                   printf ("0");
            }
        }
        printf ("\n");
    }
}
