#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, turn;
int freq[15];

int main () {
    scanf(" %d", &n);

    turn = 1;
    for (int i = n + 1; i <= 100000; i++) {
        int a = i;
        bool dif = true;
        for (int j = 0; dif && j < 4; j++) {
            int dig = a % 10;
            a /= 10;
            if (freq[dig] == turn) dif = false;
            else freq[dig] = turn;
        }

        if (dif) {
            printf("%d\n", i);
            return 0;
        }
        turn++;
    }
}

