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
    if (n % 2 == 0) {
        printf("%d\n", n/2);
        for (int i = 0; i < n/2; i++) 
            printf("2 ");
        printf("\n");
    }
    else {
        printf("%d\n", 1 + (n-3)/2);
        printf("3 ");
        n -= 3;
        for (int i = 0; i < n/2; i++) 
            printf("2 ");
        printf("\n");
    }
}

