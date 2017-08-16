#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf(" %d", &n);

    if (((n + 1) / 2) % 2 == 1) {
        printf("-1\n");
    } else {
        bool turn = true;;
        for (int i = 0; i < n / 2; i++) {
            printf("%c", turn ? '+' : '-');
            turn = !turn;
        }
        turn = (n % 2 == 0) ? false : true;
        for (int i = n / 2; i < n; i++) {
            printf("%c", turn ? '+' : '-');
            turn = !turn;
        }
        printf("\n");
    }
}
