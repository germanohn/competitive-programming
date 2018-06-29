#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAX = (1 << 20) + 1;

int max_len;
int max_div[MAX];
vector<int> pot;

void sieve() {
    max_div[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!max_div[i]) {
            for (int j = i; j < MAX; j += i) 
                max_div[j] = i;
        }
    }
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int calc_permutation() {
    vector<int> num;
    for (int i = 2; i <= max_len; i++)
        num.pb(i);
    for (int i = 0; i < pot.size(); i++) {
        int p = pot[i];
        for (int k = 2; k <= p; k++) {
            int den = k;
            for (int j = 0; j < num.size(); j++) {
                int d = gcd(num[j], den);
                num[j] /= d;
                den /= d;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < num.size(); i++)
        ans *= num[i];
    return ans;
}

int main() {
    sieve();
    int x;
    while (scanf(" %d", &x) != EOF) {
        max_len = 0;
        pot.clear();
        int cur_div = 0;
        int cur_p = -1;
        while (x != 1) {
            if (max_div[x] != cur_div) {
                cur_div = max_div[x];
                cur_p++; 
                pot.pb(1);
            } else {
                pot[cur_p]++;
            }
            x /= max_div[x];
        }
        for (int i = 0; i < pot.size(); i++) {
            int p = pot[i];
            max_len += p;
        }
        int num_chains = calc_permutation();
        printf("%d %d\n", max_len, num_chains);
    }
}

