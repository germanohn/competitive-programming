#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;

int n;
int freq1[15], freq2[15];
char s[N], m[N];

int main() {
    scanf(" %d %s %s", &n, s, m);
    
    for (int i = 0; i < n; i++) {
        int num = m[i] - '0';
        freq1[num]++;
        freq2[num]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        for (int j = num; j < 10; j++) 
            if (freq1[j]) { 
                ans--, freq1[j]--;
                break;
            }
        ans++;
    }
    printf("%d\n", ans);

    ans = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        for (int j = num + 1; j < 10; j++) 
            if (freq2[j]) {
                ans++, freq2[j]--;
                break;
            }
    }
    printf("%d\n", ans);
}
