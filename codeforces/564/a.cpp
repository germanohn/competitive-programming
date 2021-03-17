#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int a[N], b[N], round_avail[N];

int main() {
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) { 
        scanf(" %d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %d", &b[i]);
        round_avail[b[i]] = i + 1;
    }

    int increasing = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == increasing + 1) {
            increasing++;
        } else {
            increasing = 0;
        }
    }

    if (increasing) {
        int last = b[n - 1];
        bool in_time = true;
        for (int i = 0; i < n && in_time; i++) {
            if (b[i] <= last)
                continue;

            int round_needed = b[i] - last - 1;
            in_time = round_avail[b[i]] <= round_needed;
        }
        if (in_time) {
            printf("%d\n", n - last);
            return 0;
        }
    }

    int waited_rounds = 0;
    for (int i = 0; i < n; i++) {
        if (!b[i])
            continue;
        int round_needed = b[i] - 1;
        int wait_for_i = round_avail[b[i]] - round_needed;
        waited_rounds = max(waited_rounds, wait_for_i);
    }

    printf("%d\n", n + waited_rounds);
}

