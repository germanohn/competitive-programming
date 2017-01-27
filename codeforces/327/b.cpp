#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 10000000;

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = N - n + 1; i <= N; i++) 
        printf("%d ", i);
    printf("\n");
}

