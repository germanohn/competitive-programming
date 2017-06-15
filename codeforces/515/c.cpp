#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int freq[15];

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == '0' || c == '1') continue;

        int a = c - '0';
        if (a == 2) freq[2]++;
        else if (a == 4) freq[2] += 2, freq[a - 1]++;
        else if (a == 6) freq[3]++, freq[a - 1]++;
        else if (a == 8) freq[2] += 3, freq[a - 1]++;
        else if (a == 9) freq[2]++, freq[3] += 2, freq[a - 2]++;
        else freq[a]++;
    }

    for (int i = 9; i >= 2; i--) {
        while (freq[i]) {
            printf("%d", i);
            freq[i]--;
        }
    }

    printf("\n");
}

