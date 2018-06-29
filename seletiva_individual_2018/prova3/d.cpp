#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int k;
        int pos[18];
        char s[18][10];
        char ans[150];
        scanf(" %d", &k);
        for (int i = 0; i < k; i++) {
            scanf(" %s", s[i]);
            pos[i] = 0;
        }
        int mask = 0;
        int p_ans = 0;
        while (mask != ((1 << k) - 1)) {
            int count_b = 0;
            int count_g = 0;
            for (int i = 0; i < k; i++) {
                if (s[i][pos[i]] == 'B')
                    count_b++;
                else if (s[i][pos[i]] == 'G') 
                    count_g++;
            }
            char letter;
            if (count_b >= count_g)
                letter = 'B';
            else 
                letter = 'G';
            ans[p_ans++] = letter;
            for (int i = 0; i < k; i++) {
                if (s[i][pos[i]] == letter)
                    pos[i]++;
                if (s[i][pos[i]] == 0)
                    mask |= (1 << i);
            }
        }
        ans[p_ans] = 0;
        printf("%s\n", ans);
    }
}

