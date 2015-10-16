#include <bits/stdc++.h>

using namespace std;

int n, f, b, t, ans;

struct tipo {
    int floor, box;
};

tipo esc[1005], at[1005];

bool comp (tipo a, tipo b) {
    return a.floor < b.floor;
}

int main () {
    scanf ("%d", &t);
    for (int i = 0; i < t; i++) {
        ans = 0;
        scanf ("%d %d %d", &n, &f, &b);
        for (int j = 0; j < n; j++) {
            scanf ("%d %d", &esc[j].floor, &esc[j].box);
        }
        sort (esc, esc + n, comp);
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (esc[j].box == 0) {
                at[k].floor = esc[j].floor;
                at[k].box = esc[j].box;
                k++;
            }     
        }
        for (int j = n-1; j >= 0; j--) {
            if (esc[j].box == 1) {
                at[k].floor = esc[j].floor;
                at[k].box = esc[j].box;
                k++;
            }
        }
        int quant, quem, a;
        quant = b/n;
        quem = b%n;
        if (at[quem].box == 0)
            a = f + at[quem].floor;
        else 
            a = f - at[quem].floor;
        ans = f * n + a;   
        printf ("%d\n", ans);        
    }
}
