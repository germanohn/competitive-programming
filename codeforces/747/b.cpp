#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int freq[300];
char s[300], gen[5] = {'A', 'C', 'G', 'T'};

int main () {
    scanf(" %d %s", &n, s);
    for (int i = 0; s[i] != 0; i++) 
        freq[s[i]]++;
    int p = 0;
    bool ok = true;
    if (n % 4 != 0) ok = false;
    for (int i = 0; ok && i < 4; i++) 
        if (freq[gen[i]] > n/4) ok = false;
    if (!ok) {
        printf("===\n");
        return 0;
    }
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '?') {
            while (freq[gen[p]] == n/4) p++;
            printf("%c", gen[p]);
            freq[gen[p]]++;
            if (freq[gen[p]] == n/4) p++;
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

