#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans;
int s[5][5], t[5][5];
vector<int> v;

bool is_magic() {
    bool ok = true;
    
    for (int i = 0; ok && i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) 
            sum += t[i][j];

        if (sum != 15) ok = false;
    }

    for (int j = 0; ok && j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) 
            sum += t[i][j];

        if (sum != 15) ok = false;
    }

    int sum = 0;
    for (int i = 0; ok && i < 3; i++) 
        sum += t[i][i];

    if (sum != 15) ok = false;

    sum = 0;
    for (int i = 0; ok && i < 3; i++) 
        sum += t[i][2 - i];

    if (sum != 15) ok = false;

    return ok;
}

int main () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %d", &s[i][j]);
        }
    }

    for (int i = 1; i <= 9; i++)
        v.pb(i);

    ans = 1e5;
    do {
        int cur = 0, sum = 0;
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++) {
                t[i][j] = v[cur++];
                sum += abs(t[i][j] - s[i][j]);
            }

        if (is_magic()) 
            ans = min(ans, sum);
        
    } while(next_permutation(v.begin(), v.end())); 

    printf("%d\n", ans);
}

