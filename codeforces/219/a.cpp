#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int freq[105];

int main () {
    int k;
    char s[1005];
    scanf(" %d %s", &k, s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i] - 'a']++;

    bool ok = true;
    for (int i = 0; ok && i <= 'z' - 'a'; i++) 
        if (freq[i] % k != 0) 
            ok = false;
    if (!ok) 
        printf("-1\n");
    else {
        char ans[1005];
        int p_ans = 0;
        for (int j = 0; j <= 'z' - 'a'; j++) {
            for (int l = 0; l < freq[j]/k; l++) 
                ans[p_ans++] = j + 'a';
        }
        ans[p_ans] = 0;
        for (int i = 0; i < k; i++) 
            printf("%s", ans);
        printf("\n");
    }
}

