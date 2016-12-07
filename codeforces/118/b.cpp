#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    scanf(" %d", &n);
    int l, r;
    l = r = n;
    for (int i = 0; i < 2*n + 1; i++) {
        int num = 0;
        for (int j = 0; j < 2*n + 1; j++) {
            if (j >= l && j <= r) {
                int mid = (l + r + 1) / 2;
                if (j == r) 
                    printf("%d", num);
                else 
                    printf("%d ", num);
                if (j < mid) 
                    num++;    
                else 
                    num--;
            } else if (j < l) {
                printf("  ");
            }
        }
        printf("\n");
        if (i < n) 
            l--, r++;
        else
            l++, r--;
    }
}

