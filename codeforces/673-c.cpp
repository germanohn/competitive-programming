#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5005;

int n;
int v[MAX], freq[MAX], ans[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            freq[j] = 0;
        }
        int mx = 0, num;
        for (int j = i; j <= n; j++) {
            freq[v[j]]++;
            if (freq[v[j]] > mx) {
                mx = freq[v[j]];
                num = v[j];
            } else if (freq[v[j]] == mx) {
                if (v[j] < num)
                    num = v[j];
            }
            ans[num]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf ("%d ", ans[i]);
    }
    printf ("\n");
}
