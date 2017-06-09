#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5 + 5;

int n;
string s[N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        cin >> s[i];

    for (int i = n - 2; i >= 0; i--) {
        int sz = min(s[i].length(), s[i + 1].length());
        int j;
        for (j = 0; j < sz && s[i][j] == s[i + 1][j]; j++);
        if (s[i][j] > s[i + 1][j])
            s[i] = s[i].substr(0, j);
    }

    for (int i = 0; i < n; i++) 
        cout << s[i] << "\n";
}
