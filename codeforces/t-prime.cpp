#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX 1000005
#define MAXN 100010

using namespace std;

int n;
long long int primo[MAX], a[MAX], v[MAX];

void crivo () {
    for (int i = 2; i <= MAX; i++)
        if (primo[i] != 0)
            for (int j = 2; j*i <= MAX; j++) 
                primo [i*j] = 0;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    for (int i = 2; i <= MAX; i++)
        primo[i] = 1;

    crivo ();    
    int j = 0;
    for (int i = 2; i <= MAX; i++)
        if (primo[i] != 0)
           a[j++] = (long long) i*i;

    for (int i = 0; i < n; i++) {
        if (binary_search (a, a + j, v[i])) 
            cout << "YES\n";
        else 
            cout << "NO\n";   
    }
    return 0;
}
