#include<bits/stdc++.h>
using namespace std;

int a[104];

bool cmp(int x, int y) {
    if (x % 2 == 1) return true;
    return false;
}

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        scanf(" %d", &a[i]);
    }

    sort(a, a + k, cmp);
    
    int cor = 2 * n;
    int row = 0, col = 0; 
    for (int i = 0; i < k; i++) {
        while (a[i] > 0 && row < n) {
            if (col == 0) {
                if (a[i] >= 4) {
                    col = 0, row++;
                    a[i] -= 4;
                } else if (a[i] == 3) {
                    col = 0, row++;
                    a[i] = 0;
                } else if (a[i] == 2) {
                    col = 3;
                    a[i] = 0;
                } else {
                    col = 2;
                    a[i] = 0;
                }
            } else if (col == 2) {
                if (a[i] >= 2) {
                    a[i] -= 2;
                } else {
                    a[i]--;
                }
                col = 0, row++;
            } else if (col == 3) {
                col = 0, row++;
                a[i]--;
            }
        }

        if (a[i]) {
            if (cor >= (a[i] + 1) / 2) {
                cor -= (a[i] + 1) / 2;
                a[i] = 0;
            } else {
                //printf("cor %d a %d\n", cor, a);
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
}

