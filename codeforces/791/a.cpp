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
    int year = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        year++;
    }
    printf("%d\n", year);
}

