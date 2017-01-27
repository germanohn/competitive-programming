#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
priority_queue<pii> pq;
map<int, int> freq;

int main() {
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        freq[a]++;
    }    

    for (auto it : freq) {
        int f, v;
        tie(v, f) = it;
        pq.push(pii(f, v));
    }

    int cont, pos;
    cont = pos = 0;
    int ans[MAX][5];
    pii tri[5];
    while (!pq.empty()) {
        tri[cont] = pq.top();
        pq.pop();
        tri[cont++].ff--;

        if (cont == 3) {
            if (tri[0].ff > 0) pq.push(tri[0]);
            if (tri[1].ff > 0) pq.push(tri[1]);
            if (tri[2].ff > 0) pq.push(tri[2]);
            ans[pos][0] = tri[0].ss, ans[pos][1] = tri[1].ss, ans[pos][2] = tri[2].ss;
            cont = 0, pos++;            
        }
    }

    printf("%d\n", pos);
    for (int i = 0; i < pos; i++) {
        sort(ans[i], ans[i] + 3);
        printf("%d %d %d\n", ans[i][2], ans[i][1], ans[i][0]);
    }
}
