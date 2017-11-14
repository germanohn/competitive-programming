#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 15;

int t;
string s;
set<string> s1, s2;

int main () {
    scanf(" %d", &t);
    while (t--) {
        cin >> s;
        s1.clear(), s2.clear();
        for (int i = 0; s[i] != 0; i++) {
            for (int j = 0; s[j] != 0; j++) {
                string sub, rev;
                for (int k = i; k <= j; k++) {
                    sub += s[k];
                    rev += s[j - k];
                }
                s1.insert(sub);
                s2.insert(rev);
            }
        }

        bool ok = true;
        for (auto it = s2.begin(); ok && it != s2.end(); it++) {
            if (s1.find(*it) == s1.end()) 
                ok = false;
        }

        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}

