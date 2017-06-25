#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[10];

int main() {
    while (scanf(" %s", s) && s[0] != 'E') {
        int len = strlen(s);
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != '0') {
                s[i] = s[i] - 1;
                break;
            }
        }
        int n = atoi(s);
        printf("%d\n", n);
    }
}
