#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    bool color = false;
    scanf(" %d", &n);
    while (n--) {
        char p;
        scanf(" %c", &p);
        if (p == '(') 
            color = !color;
        printf("%c", color ? '1' : '0');
        if (p == ')')
            color = !color;
    }
}

