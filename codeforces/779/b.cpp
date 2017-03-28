#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main () {
    int n, k;
    char s[15];
    scanf(" %d %d", &n, &k);
    sprintf(s, "%d", n);

    int zeros = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '0') 
            zeros++;
    }

    if (zeros < k) {
        printf("%d\n", strlen(s) - 1);
    } else {
        zeros = 0;
        int len = strlen(s);
        int i = len - 1;
        while (zeros < k && i >= 0) {
            if (s[i] == '0')
                zeros++;
            i--;
        }
        i++;
        printf("%d\n", len - i - zeros);
    }
}

