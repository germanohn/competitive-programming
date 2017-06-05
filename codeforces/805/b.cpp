#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main () {
    scanf(" %d", &n);
    int a = 2, b = 2;
    for (int i = 0; i < n; i++) {
        if (a) {
            a--;
            printf("a");
            if (!a && !b) b = 2;
        } else if (b) {
            b--;
            printf("b");
            if (!b && !a) a = 2;
        }
        
    }
    printf("\n");
}

