#include<bits/stdc++.h>
using namespace std;

const int N = 30; 

int num_wa[N];
bool first_ac[N];

int main() {
    int n, k;
    int penalty = 0;
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        char letter;
        int _time;
        char veredict[5];
        scanf(" %c %d %s", &letter, &_time, veredict);
        int problem = letter - 'A';
        if (veredict[0] == 'A' && veredict[1] == 'C') {
            if (!first_ac[problem]) {
                first_ac[problem] = true;
                penalty += _time + num_wa[problem] * 20;
            } 
        } else {
            num_wa[problem]++;
        }
    }
    printf("%d\n", penalty);
}

