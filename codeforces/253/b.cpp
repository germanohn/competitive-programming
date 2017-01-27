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
    FILE * in;
    FILE * out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    fscanf(in, " %d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(in, " %d", &v[i]);
    }
    sort(v, v + n);
    int l = 0, r = n - 1;
    while (v[r] > 2 * v[l]) l++;
    int ans = (n - 1) - r + l;
    while (l != 0) {
        l--;
        while (v[r] > 2 * v[l]) r--;
        ans = min(ans, (n - 1) - r + l);
    }
    fprintf(out, "%d\n", ans);
    fclose(in);
    fclose(out);
}
