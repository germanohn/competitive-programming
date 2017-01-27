#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n;
pii pto[MAX];

double dis(pii a, pii b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d %d", &pto[i].x, &pto[i].y);

    pii c;
    bool f = false;
    for (int i = -1000; !f && i <= 1000; i++) {
        for (int j = -1000; !f && j <= 1000; j++) {
            f = true;
            for (int l = 0; f && l < n; l++) {
                if (i != pto[l].x || j != pto[l].y) {
                    c.x = i, c.y = j;
                } else {
                    f = false;
                }
            }
        }
    }

    double r = -1;
    for (int i = 0; i < n; i++) 
        r = max(r, dis(c, pto[i]));       

    printf("%d %d %.9lf\n", c.x, c.y, sqrt(r));
}
