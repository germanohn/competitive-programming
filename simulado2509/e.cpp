#include <bits/stdc++.h>
#define MAX 25010
#define ff first
#define ss second

using namespace std;

int n, t, freq[MAX], ult[MAX];
char v[MAX], c;
map<char, int> m;

int main () {
    scanf ("%d", &t);
    
    while (t--) {
        m.clear();
        memset(freq,0,sizeof freq);
        int k = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
            scanf (" %c", &c);
            v[i] = c;
            if(m.find(c) == m.end()) m[c] = k++;
            ult[m[c]] = i;
            freq[m[c]]++;
        }
        int podre, ans;
        ans = podre = 0;
        for (int i = 0; i < n; i++) {
            podre += 5 * (ult[m[v[i]]] - i);
        }
        for(int i = 0; i < 170; i++) {
            int num = freq[i];
            if (num == 2) ans += 5;
            else if(num >= 3)
                ans += 5 + (num - 2) * 10 + ((num - 3) * (5 + (num - 3) * 5)) / 2;
        }
        ans = podre - ans;
        printf ("%d\n", ans);
    }
}
