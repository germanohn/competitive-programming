#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, zeros;
vector<int> neg, pos;

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        if (a < 0) neg.pb(a);
        else if (a == 0) zeros++;
        else pos.pb(a);
    }
    printf("1 %d\n", neg[0]);

    int p_neg = 1;
    if (pos.size() != 0) {
        printf("%d ", pos.size());
        for (int i = 0; i < pos.size(); i++) 
            printf("%d ", pos[i]);
        printf("\n");
    } else {
        printf("2 %d %d\n", neg[1], neg[2]);
        p_neg = 3;
    }

    printf("%d ", neg.size() - p_neg + zeros);
    for (int i = p_neg; i < neg.size(); i++) 
        printf("%d ", neg[i]);
    for (int i = 0; i < zeros; i++) 
        printf("0 ");
    printf("\n");
}

