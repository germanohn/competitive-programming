#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 200005
#define pb push_back

using namespace std;

int n, c, m[MAX][2], maior;
vector<int> p;

void pd () {
    for (int i = n-1; i >= 0; i--) {
        m[i][0] = max (m[i+1][0], m[i+1][1] + p[i]);
        m[i][1] = max (m[i+1][1], m[i+1][0] -c -p[i]);
    } 
}

int main () {
    while (scanf ("%d %d", &n, &c) != EOF) {
        for (int i = 0; i < n; i++) {
            int a;
            scanf ("%d", &a);
            p.pb (a);
        }
        m[n][0] = 0;
        m[n][1] = 0;
        pd ();
        printf ("%d\n", m[0][1]);
        p.clear ();
    }
}
