// tag:implementation,difficulty:medium,
#include<bits/stdc++.h>
using namespace std;

#define N 112345
#define MAX 1e12

typedef long long ll;

ll t[N], x[N];

/*
ll sig(ll a) {
    if (a < 0)
        return -1;
    return a > 0;
}
*/

ll signal(ll pos, ll goal_pos) {
    if (pos > goal_pos) 
        return -1;
    return pos < goal_pos;
}

bool between(ll l, ll r, ll pos) {
    return (min(l, r) <= pos) && (pos <= max(l, r));
}

int main() {
    int ans;
    int cases; 
    scanf(" %d", &cases);
    while (cases--) {
        ans = 0;

        int n;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %lld %lld", &t[i], &x[i]);
        }
        t[n] = MAX;

        ll end_t = 0; // time that com finishes
        ll pos = 0; // current position
        ll com = 0; // last command not ignored
        ll dir = 0; // direction of robot movement

        for (int i = 0; i < n; i++) {   
            // test if command is ignored and update variables
            if (t[i] >= end_t) {
                // command is not ignored
                pos = (i == 0) ? 0 : x[com];
                end_t = t[i] + abs(x[i] - pos);
                com = i;
                dir = signal(pos, x[com]);
            } else {
                ll elapsed_t = t[i] - t[i - 1];
                pos += dir * elapsed_t;
            }
            // test if command is successful
            ll avail_t = min(end_t, t[i + 1]) - t[i];
            ll nx_pos = pos + dir * avail_t;
            if (between(pos, nx_pos, x[i]))
                ans++;
        }

        /* second: solution: use left instead of end_t and update pos at the end of for 
        ll left = 0; // time to com finishes 
        ll pos = 0;
        ll dir = 0;
        for (int i = 0; i < n; i++) {
            if (left == 0) {
                left = abs(x[i] - pos);
                dir = sig(x[i] - pos]);
            }
            ll avail_t = min(left, t[i + 1] - t[i]);
            ll nx_pos = pos + dir * avail_t;
            if (between(pos, nx_pos, x[i]))
                ans++;
            pos = nx_pos;
            left -= avail_t;
        }*/

        printf("%d\n", ans);
    }
}

