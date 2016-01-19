#include <bits/stdc++.h>
using namespace std;

int res, depo;

int dp (int i, int k) {
    if (k == 0) {
        int sum = 0;
        for (int j = i+1; j < res; j++)
           sum += r[j]-r[i];
        return me[i][k] = sum; 
    }
    if (i == res-1) return 123456;
    int &m = me[i][k];
    if (m != -1) return m;
    int ans = INT_MAX;
    for (int j = i+1; j < res; j++) {
        int sum = 0;


        ans = min (ans, sum);
    }
}

int main () {
    while(scanf("%d%d",&res,&depo) && res != 0 && depo != 0) {
        for (int i = 0; i < res; i++) 
            scanf ("%d", &r[i]);
        int ans = 0;
        for (int i = 0; i < res; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) 
                sum += r[i]-r[j];
            sum += dp (i+1, depo-1);
            ans = max (ans, sum);
        }
    }
}
