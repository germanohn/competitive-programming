#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
bool seen[MAX];

int main () {
    scanf(" %d", &n);
    int ult = n;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        seen[a] = true;
        while (ult >= 1 && seen[ult]) {
            printf("%d ", ult--);
        }
        printf("\n");
    }
}

