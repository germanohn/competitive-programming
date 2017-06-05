#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;

char s1[N], s2[N], ans[N];
vector<char> ol, ig;

int main () {   
    scanf(" %s %s", s1, s2);
    int n = strlen(s1);

    for (int i = 0; i < n; i++) {
        ol.pb(s1[i]);
        ig.pb(s2[i]);
    }

    sort(ol.begin(), ol.end());
    sort(ig.begin(), ig.end(), greater<char>());

    for (int i = n - 1; i >= (n + 1) / 2; i--) 
        ol.pop_back();
    for (int i = n - 1; i >= n / 2; i--) 
        ig.pop_back();

    int lo = 0, ro = ol.size() - 1;
    int lg = 0, rg = ig.size() - 1;
    int l = 0, r = n - 1;
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (ol[lo] < ig[lg]) {
            ans[l++] = ol[lo++]; // ok
        } else {
            ans[r--] = ol[ro--];
        }

        if (i == ((n + 1) / 2) - 1 && (n % 2 == 1)) 
            continue;
        if (ig[lg] > ol[lo]) {
            ans[l++] = ig[lg++];
        } else {
            ans[r--] = ig[rg--];
        }
    }

    printf("%s\n", ans);
}

