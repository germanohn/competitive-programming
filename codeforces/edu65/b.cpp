#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int v[6] = {4, 8, 15, 16, 23, 42};

int divis(int val, int idx) {
    if (val == 1) return 1;

    for (int i = idx; i < 6; i++) {
        if (val % v[i] == 0 && divis(val / v[i], i + 1))
            return v[i];
    }
    return 0;
}

int main() {
    int ans[6];
    vector<int> cand;

    for (int i = 0; i <= 3; i += 3) {
        int res;

        printf("? %d %d\n", i + 1, i + 2);
        fflush(stdout);
        scanf(" %d", &res);
        //printf("1 div %d\n", divis(res, 0));
        cand.pb(divis(res, 0));
        cand.pb(res / cand[0]);

        printf("? %d %d\n", i + 2, i + 3);
        fflush(stdout);
        scanf(" %d", &res); 
        //printf("2 div %d\n", divis(res, 0));

        /*for (int j = 0; j < 2; j++)
            printf("%d ", cand[j]);
        printf("\n");*/

        int factor = divis(res, 0);
        //printf("factor %d\n", factor);
        if (cand[0] == factor || cand[0] == res / factor) {
            ans[i] = cand[1];
            ans[i + 1] = cand[0];
            ans[i + 2] = res / cand[0];
        } else {
            ans[i] = cand[0];
            ans[i + 1] = cand[1];
            ans[i + 2] = res / cand[1];
        }
        cand.clear();
    }

    printf("! ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    fflush(stdout);
}

