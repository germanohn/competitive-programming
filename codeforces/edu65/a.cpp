#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int t;
    char s[105];
    scanf(" %d", &t);
    while (t--) {
        int len;
        bool rta = 0;
        scanf(" %d", &len);
        scanf(" %s", s);
        for (int i = 0; i <= len - 11; i++) {
            if (s[i] == '8') {
                rta = 1;
                break;
            }
        }
        printf("%s\n", rta ? "YES" : "NO"); 
    }
}

