#include<bits/stdc++.h>
using namespace std;

int main() {
    int f;
    int freq[3]; // -|D: 0, R|-: 1, R|D: 2
    while (scanf(" %d", &f) != EOF) {
        for (int i = 0; i < 3; i++) 
            freq[i] = 0;
        char s[105];
        int dr = 0;
        for (int i = 0; i < f; i++) {
            scanf(" %s", s);
            bool only_r = false;
            char ult = '$';
            for (int i = 0; s[i] != 0; i++) {
                if (s[i] == 'D') {
                    ult = 'D';
                } else if (s[i] == 'R') {
                    if (ult == 'D') 
                        dr++;
                    else if (ult == '$')
                        only_r = true;
                    ult = 'R';
                }
            }
            if (ult == 'D') {
                if (only_r) freq[2]++, only_r = false;
                else freq[0]++;
            }
            if (only_r) freq[1]++;
        }
        if (freq[0] || freq[1]) {
            dr += min(freq[0], freq[1]) + freq[2];
        } else {
            dr += max(0, freq[2] - 1);
        }
        printf("%d\n", dr);
    }
}

