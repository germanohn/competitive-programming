#include<bits/stdc++.h>
using namespace std;

int n;
int v[1005];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    if (v[0] == 1) printf("-1\n");
    else printf("1\n");
}
