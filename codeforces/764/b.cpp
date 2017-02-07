#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) 
            swap(v[i], v[n - i - 1]);
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    printf("\n");
}

