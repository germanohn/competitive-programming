#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;

ll n, k;
char f0[N] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char pri[N] = "What are you doing while sending \"";
char seg[N] = "\"? Are you busy? Will you send \"";
char ter[N] = "\"?";
ll len_pri, len_seg, len_ter;
ll len_f[N];

void init() {
    len_pri = strlen(pri);
    len_seg = strlen(seg);
    len_ter = strlen(ter);

    ll a = 75, r = 143;
    for (int i = 0; i < 54; i++) {
        len_f[i] = a;
        a += r;
        r *= 2;
    }
}

char find() {
    if (n < 54 && len_f[n] < k) return '.';
    char c = '-';
    while (k > 0 && n > 0) {
        if (n > 53) {
            if (len_pri >= k) {
                c = pri[k - 1];     
                k = 0;
            } else {
                k -= len_pri;
                n--;
            }
        } else {
            if (len_pri >= k) {
                c = pri[k - 1];
                k = 0;
                continue;
            } else {
                k -= len_pri;
            }

            if (len_f[n - 1] >= k) {
                n--;
                continue; 
            } else {
                k -= len_f[n - 1];
            }

            if (len_seg >= k) {
                c = seg[k - 1];
                k = 0;
                continue;
            } else {
                k -= len_seg;
            }

            if (len_f[n - 1] >= k) {
                n--;
                continue;
            } else {
                k -= len_f[n - 1];
            }

            c = ter[k - 1];
            k = 0;
        }
    }
    if (c == '-') {
        c = f0[k - 1];
        k = 0;
    }
    return c;
}

int main() {
    int q;
    scanf(" %d", &q);
    init();
    while (q--) {
        scanf(" %lld %lld", &n, &k);
        printf("%c", find()); 
    }
    printf("\n");
}

