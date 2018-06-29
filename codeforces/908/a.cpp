#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int cont = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
                cont++;
        } else {
            int num = s[i] - '0';
            if (num % 2 == 1) 
                cont++;
        }
    }
    printf("%d\n", cont);
}

