#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int a[N];
ll freq[N];
vector<int> tri;

int main () {
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    sort(a, a + n);
    for (int i = 0; i < 3; i++)
        tri.pb(a[i]);
    tri.resize(unique(tri.begin(), tri.end()) - tri.begin());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tri.size(); j++) {
            if (a[i] == tri[j]) {
                freq[j]++;
                break;
            }
        }
    }

    if (freq[0] >= 3) {
        printf("%lld\n", freq[0] * (freq[0] - 1) * (freq[0] - 2) / (3 * 2));
    } else if (freq[0] == 2) {
        printf("%lld\n", freq[1]);
    } else if (freq[0] == 1 && freq[1] >= 2) {
        printf("%lld\n", freq[1] * (freq[1] - 1) / 2);
    } else {
        printf("%lld\n", freq[2]);
    }
}

