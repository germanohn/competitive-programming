#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b;

int main () {
    scanf(" %d %d", &a, &b);

    int cont_a = 0, cur = 1;
    while (a >= cur) {
        a -= cur;
        cur += 2;
        cont_a++;
    }

    int cont_b = 0;
    cur = 2;
    while (b >= cur) {
        b -= cur;
        cur += 2;
        cont_b++;
    }

    if (cont_a > cont_b) {
        printf("Valera\n");
    } else {
        printf("Vladik\n");
    }
}

