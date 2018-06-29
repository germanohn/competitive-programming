#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    char s[55];
    scanf(" %s", s);
    int longest = 0;
    for (int i = 0; s[i] != 0; i++) {
        int cur = 1;
        int l = i;
        for (int j = i + 1; s[j] != 0; j++) {
            if (s[j] == s[l] + 1) {
                cur++;
                l = j;
            }
        }
        longest = max(longest, cur);
    }
    printf("%d\n", 26 - longest);
}

