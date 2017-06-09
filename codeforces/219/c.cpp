#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500005;

int n, k;
char s[MAX];

int main() {
    scanf(" %d %d %s", &n, &k, s);
    int repaints = 0;
    if (k == 2) {
        int a = 0, b = 0;
        char ca = 'A', cb = 'B';
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] != ca) a++;
            if (s[i] != cb) b++;
            swap(ca, cb);
        }
        repaints = min(a, b);
        printf("%d\n", repaints);
        if (a < b) 
            ca = 'A', cb = 'B';
        else 
            ca = 'B', cb = 'A';
        for (int i = 0; s[i] != 0; i++) {
            printf("%c", ca);
            swap(ca, cb);
        }
        printf("\n");
    } else {
        int len = 1;
        char cur = s[0];
        int l = strlen(s);
        for (int i = 1; i < l + 1; i++) {
            if (s[i] != cur) {
                repaints += len / 2;
                char dif;
                for (int j = 0; j < k; j++) {
                    dif = j + 'A';
                    if (dif != cur && dif != s[i])
                        break;
                }
                for (int j = i - len + 1; j < i; j += 2) 
                    s[j] = dif;
                len = 1; cur = s[i];
            } else 
                len++;
        }
        printf("%d\n%s\n", repaints, s);
    }
}
