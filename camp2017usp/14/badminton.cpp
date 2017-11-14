#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double sr[2];
double me[4][4][31][31][2];

double dp(int g1, int g2, int p1, int p2, int s) {
    if (g1 == 2) return 1.;
    if (g2 == 2) return 0.;
    if (me[g1][g2][p1][p2][s] != -1.) return me[g1][g2][p1][p2][s];

    double ans = 0.;
    // ganha ponto
    if (p1 == 29 || (p1 >= 20 && p1 - p2 >= 1)) {
        ans = double(sr[s]) * dp(g1 + 1, g2, 0, 0, 0);
    } else {
        ans = double(sr[s]) * dp(g1, g2, p1 + 1, p2, 0);
    }

    // perde ponto
    if (p2 == 29 || (p2 >= 20 && p2 - p1 >= 1)) {
        ans += double((1 - sr[s])) * dp(g1, g2 + 1, 0, 0, 1);
    } else {
        ans += double((1 - sr[s])) * dp(g1, g2, p1, p2 + 1, 1);
    }

    return me[g1][g2][p1][p2][s] = ans;
}

int main () {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int p1 = 0; p1 < 31; p1++) {
                for (int p2 = 0; p2 < 31; p2++) {
                    for (int s = 0; s < 2; s++) 
                        me[i][j][p1][p2][s] = -1.;
                }
            } 
        }
    }
    scanf(" %lf %lf", &sr[0], &sr[1]);
    sr[0] /= 1e9;
    sr[1] /= 1e9;
    printf("%.15lf\n", dp(0, 0, 0, 0, 0));
}

