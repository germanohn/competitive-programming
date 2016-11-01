#include<bits/stdc++.h>
#define x first
#define y second
#define int long long 
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, a1, b1;
pii pto_1, pto_2;
pii pto[MAX], ori[MAX];

int cross(pii a, pii b) {
    return (a.x - pto_1.x) * (b.y - pto_1.y) - (a.y - pto_1.y) * (b.x - pto_1.x);
}

bool cmp(pii a, pii b) {
    if (cross(a, b) < 0) return 1;
    return 0; 
}

main() {
    scanf(" %d", &n);

    pto_1.x = 1e9 + 1;
    for (int i = 0; i < n; i++) { 
        scanf(" %lld %lld", &pto[i].x, &pto[i].y);
        ori[i].x = pto[i].x, ori[i].y = pto[i].y;
        if (pto[i].x < pto_1.x)
            pto_1.x = pto[i].x, pto_1.y = pto[i].y;
    }

    sort(pto, pto + n, cmp);

    for (int i = 0; i < n; i++) {
        if (i - 1 == n - i - 1) {
            pto_2.x = pto[i].x, pto_2.y = pto[i].y;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ori[i].x == pto_1.x && ori[i].y == pto_1.y)
            printf("%lld ", i + 1);
        if (ori[i].x == pto_2.x && ori[i].y == pto_2.y)
            printf("%lld ", i + 1);       
    }
    printf("\n");
}
