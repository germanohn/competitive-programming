#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int a[10];

int main() {
    int tot = 0;
    for (int i = 0; i < 6; i++) {
        scanf(" %d", &a[i]);
        tot += a[i];
    }

    if (tot % 2 == 1) {
        printf("NO\n");
        return 0;
    }

    int team1 = 0;
    for (int i = 0; i < 4; i++) {
        team1 = a[i];
        for (int j = i + 1; j < 5; j++) {
            team1 += a[j];
            for (int k = j + 1; k < 6; k++) {
                team1 += a[k];
                if (team1 == tot / 2) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }

    printf("NO\n");
}

