#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int k, sz_ans;
int pos[18];
char s[18][10];
char aux[18], ans[18];

bool try_necklace(int i) {
    int count = 0;
    for (int j = 0; j < k; j++) {
        if (s[j][pos[j]] == aux[i]) 
            pos[j]++;
        if (s[j][pos[j]] == 0)
            count++;
    }
    if (count == k && i + 1 < sz_ans) {
        for (int j = 0; j < i + 1; j++)
           ans[j] = aux[j];
        sz_ans = i + 1; 
    }
    return count == k;
}

void find_min_necklace(int i) {
    if (i == 16)
        return;
    aux[i] = 'B';
    if (!try_necklace(i)) {
        find_min_necklace(i + 1);
        undo_necklace(i);
        aux[i] = 'G';
        if (!try_necklace(i)) {
            find_min_necklace(i + 1);
            undo_necklace();
        }
    }
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &k);
        sz_ans = 17;
        for (int i = 0; i < k; i++) {
            scanf(" %s", s[i]);
            pos[i] = 0;
        }
        find_min_necklace(0);
        printf("%s\n", ans);
    }
}

