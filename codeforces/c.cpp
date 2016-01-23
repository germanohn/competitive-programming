#include <bits/stdc++.h>
using namespace std;

int d[2005][2];

struct no {
    int x, int y;
    float d;
};

no dis[2005];

float distance (int x, int y, int a, int b) {
    return sqrt ((x-a)*(x-a) + (y-b)*(y-b));
}

bool compare (

int main () {
    int n, x1, y1, x2, y2, a, b;
    scanf ("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &d[i][0], &d[i][1]);

    }
}
