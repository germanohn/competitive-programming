#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n;
int v[MAX];
bool seen[MAX];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        seen[i] = true, ans++;
        int size = 1;
        for (int j = i + 1; j < n; j++) {
            if (!seen[j] && v[j] >= size) 
                seen[j] = true, size++;
        }
    }
    printf("%d\n", ans);
}
