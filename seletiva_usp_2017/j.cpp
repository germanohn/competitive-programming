#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
bool turn;
char s[2][20];
char sn[20], sk[20];
ll me[20][200][10][2];

ll dp(int i, int sum, int ud, bool eq) {
    if (i == 18) return (!sum) ? 1 : 0;
    ll &m = me[i][sum][ud][eq];
    if (m != -1) return m;

    m = 0;
    for (int j = 0; j < 10; j++) {
        if (sum - j < 0) break;
        if (eq && (j > s[turn][i] - '0')) break;

        m += dp(i + 1, sum - j, j, eq & (j == (s[turn][i] - '0')));
    }

    return m;
}

void move_string(int kind) {
    char aux[20];
    int len_s = strlen(s[kind]);

    for (int i = 0; i < 18; i++) {
        if (i < 18 - len_s) aux[i] = '0';
        else aux[i] = s[kind][i - (18 - len_s)];
    }
 
    for (int i = 0; i < 18; i++) 
        s[kind][i] = aux[i];
}

int main() {
    memset(me, -1, sizeof me);
    scanf(" %lld %lld", &n, &k);
    sprintf(s[0], "%lld", n);
    sprintf(s[1], "%lld", k);

    int sum_k = 0;
    for (int i = 0; s[1][i] != 0; i++) 
        sum_k += (s[1][i] - '0');

    move_string(0);
    move_string(1);

    ll ans = 0;
    turn = false;
    for (int i = 1; i < sum_k; i++) 
        ans += dp(0, i, 0, true);
    turn = true;
    ans += dp(0, sum_k, 0, true);

    printf("%lld\n", ans);

    ans = 0;
    int acc = 0, sum;
    for (int i = 1; i < 163; i++) {
        int cur_sum = dp(0, i, 0, true);
        if (acc + cur_sum >= k) { 
            sum = i;
            break;
        }
        else acc += cur_sum;
    }

    printf("sum %d acc %d\n", sum, acc);

    turn = false;
    char ans_s[20];
    int target = k - acc, ans_p = 0;
    bool eq = true;
    for (int i = 0; i < 18; i++) {
        printf("i %d\n", i);
        for (int j = 0; j < 10; j++) {
            if (sum - j < 0) break;
            ans_s[ans_p] = j + '0';
            
            int cur_q = dp(i, sum - j, 0, false);
            printf("cur_q %lld target %lld\n", cur_q, target);
            if (cur_q < target) { 
                target -= cur_q;
            } else {
                ans_p++, sum -= j;
                break;
            }
        }
        printf("\n");
    } 
    ans_s[ans_p] = 0;

    printf("%s\n", ans_s);
}

