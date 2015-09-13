#include <cstdio>
#include <algorithm>

using namespace std;

int n, primo[1005], ans, a[1005];

void crivo () {
    for (int i = 2; i <= n; i++) {
        if (primo[i] != 0)
            for (int j = 2; j * i <= n; j++) 
                primo[i*j] = 0;
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i <= n; i++) 
        primo[i] = i;
    crivo ();
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (primo[i] != 0) 
            primo[j++] = primo[i];
    }
    int k = 0, aux = n;
    for (int i = 0; i < j; i++) {
        int num = primo[i];
        while (num <= n && num != 1) {
            a[k++] = num;
            num *= primo[i]; 
        }    
    }
    printf ("%d\n", k);
    for (int i = 0; i < k; i++) 
        printf ("%d ", a[i]);
    printf ("\n");
}
