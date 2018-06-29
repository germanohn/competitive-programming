#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
const int C = 5e5;

struct Point {
    int x, y;
};

struct Query {
    int x, y, id;
};

int n, m;
int pre[4 * C], suf[4 * C];
Point coin[N];
Query line[N];

void update(int no, int l, int r, int target, int val, char k) {
    if (target < l || target > r) 
        return;
    if (l == r) {
        if (k == 'p') {
            pre[no] += val;
        } else {
            suf[no] += val;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * no, l, mid, target, val, k);
    update(2 * no + 1, mid + 1, r, target, val, k);
    if (k == 'p') {
        pre[no] = pre[2 * no] + pre[2 * no + 1];
    } else {
        suf[no] = suf[2 * no] + suf[2 * no + 1];
    }
}

int query(int no, int l, int r, int tl, int tr, char k) {
    if (tr < l || tl > r)
        return 0;
    if (l >= tl && r <= tr) {
        if (k == 'p') {
            return pre[no];
        } else {
            return suf[no];
        }
    }
    int mid = (l + r) / 2;
    return query(2 * no, l, mid, tl, tr, k) + query(2 * no + 1, mid + 1, r, tl, tr, k);
} 

bool cmp1(Point a, Point b) {
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

bool cmp2(Query a, Query b) {
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

void clean() {
    for (int i = 0; i < 4 * C; i++) {
        pre[i] = suf[i] = 0;
    }
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &m);
        clean();
        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &coin[i].x, &coin[i].y);
        }
        for (int i = 0; i < m; i++) {
            scanf(" %d %d", &line[i].x, &line[i].y);
            line[i].id = i;
        }

        sort(coin, coin + n, cmp1);
        sort(line, line + m, cmp2);

        for (int i = 0; i < n; i++) {
            update(1, 0, C, coin[i].y, 1, 's');
        }

        int p = 0;
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int bound = line[i].x;
            while (p < n && coin[p].x <= bound) {
                update(1, 0, C, coin[p].y, 1, 'p');
                update(1, 0, C, coin[p].y, -1, 's');
                p++;
            }
            int third_quad = query(1, 0, C, 0, line[i].y, 'p');
            int second_quad = p - third_quad;
            int fourth_quad = query(1, 0, C, 0, line[i].y, 's');
            int first_quad = (n - p) - fourth_quad;
            ans[line[i].id] = abs((first_quad + third_quad) - (second_quad + fourth_quad));
        }
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }

        if (t) 
            printf("\n");
    }
}

