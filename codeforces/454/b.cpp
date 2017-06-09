#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    int big = -1;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        big = max(big, v[i]);
    }
    int l;
    if (v[0] == big) {
        l = 1;
        while (v[l] == big) l++;
        for (int j = l + 1; j < n; j++) 
            if (v[j] < v[j - 1]) {
                printf("-1\n");
                return 0;
            }
    } else {
        for (int i = 0; i < n; i++) {
            if (v[i] == big) 
                l = i;
        } 
        int cont = 0;
        for (int i = (l + 1) % n; cont < n - 1; i++) {
            int pre = v[i % n], cur = v[(i + 1) % n];
            if (pre > cur) {
                printf("-1\n");
                return 0; 
            }
            cont++;
        }
        l++;
    }
    printf("%d\n", n - l);
}

