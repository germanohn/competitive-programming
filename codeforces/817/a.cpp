#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int X1, Y1, X2, Y2, X, Y;

int main () {
    scanf(" %d %d %d %d %d %d", &X1, &Y1, &X2, &Y2, &X, &Y);

    int dif1 = abs(X1 - X2);
    int dif2 = abs(Y1 - Y2);

    if (dif1 % X != 0 || dif2 % Y != 0) {
        printf("NO\n");
    } else {
        int q1 = dif1 / X;
        int q2 = dif2 / Y;

        if (abs(q1 - q2) % 2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

