#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 1004;
const int modn = 1000000007;

char names[MAXN][300];
int attr[MAXN][300];
vector<int> a[MAXN];
char t[300];
int perm[MAXN];
int ma;

int get_i(char *c) {
    if (strcmp(c, "upper") == 0) return 3;
    if (strcmp(c, "middle") == 0) return 2;
    if (strcmp(c, "lower") == 0) return 1;
}

bool cmp_s(int a, int b) {
    if (strcmp(names[a], names[b]) < 0) return true;
    return false;
}

bool cmp(int a, int b) {
    int i = ma-1;
    while (attr[a][i] == attr[b][i] && i >= 0) i--;
    if (i < 0) return cmp_s(a, b);
    return attr[a][i] > attr[b][i];
}

int main() {
    int n;
    scanf (" %d", &n);
    for (int i = 0; i <= n; i++) {
        perm[i] = i;
        for (int j = 0; j < 300; j++)
            attr[i][j] = 2;
    }
    for (int i = 0; i < n; i++) {
        scanf (" %[^:]", names[i]);
        scanf (" %*c");
        scanf (" %[^\n]", t);
        char *pch;
        pch = strtok(t, " ");
        while (pch != NULL) {
            if (strcmp("class", pch) != 0) a[i].pb(get_i(pch));
            if (((int) a[i].size()) > ma) ma = (int) a[i].size();
            pch = strtok(NULL, " ");
        }
    }
    for (int i = 0; i < n; i++) {
        int cur = ma - ((int) a[i].size());
        for (int j = 0; j < a[i].size(); j++)
            attr[i][j + cur] = a[i][j];
    }
    sort (perm, perm + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[perm[i]]);
    }
}

