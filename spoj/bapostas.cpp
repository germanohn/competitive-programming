#include <cstdio>
#define MAX 10010

using namespace std;

int n, v[MAX], x, y, max_total;

void kadane () {
    int x_temp = 0;
    int max_atual = 0; 
    max_total = -1;
    for (int i = 0; i < n; i++) {
        max_atual = max_atual + v[i];
        if (max_atual < 0) {
            max_atual = 0; 
            x_temp = i + 1;
        }
        if (max_atual > max_total) {
            max_total = max_atual;
            x = x_temp;
            y = i;
        }
    }
}    

int main () {
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++)
            scanf ("%d", &v[i]);
        kadane ();
        if (max_total > 0) 
            printf ("The maximum winning streak is %d.\n", max_total);
        else
            printf ("Losing streak.\n");
    }
}
