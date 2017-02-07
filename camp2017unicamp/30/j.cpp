#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
    
char s[222];
int n, a, b, cz, cu;

bool opos(int a, int b) {
    return a * b < 0;
}

void zu(){
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            s[i] = '1';
            break;
        }
    }
    cz++;
    cu--;
}

void uz() {
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            s[i] = '0';
            break;
        }
    }
    cz--;
    cu++;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d",&n,&a,&b);
    scanf(" %s", s);
    if(a+b > n) {
        puts("-1");
        return 0;
    }
    int z, u;
    z = 0, u = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') z++;
        else if(s[i] == '1') u++;
    }

    int ans = 0;
    cz = a - z;
    cu = b - u;
    while(opos(cz, cu)) {
        if(cz < 0 && cu > 0) zu();
        else uz();
        ans++;
    }
    while(cz != 0) {
        ans++;
        if(cz > 0) {
            for(int i = 0; i < n; i++) {
                if(s[i] == '2') {
                    s[i] = '0';
                    cz--;
                    break;
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(s[i] == '0') {
                    s[i] = '2';
                    cz++;
                    break;
                }
            }
        }
    }
    while(cu != 0) {
        ans++;
        if(cu > 0) {
            for(int i = 0; i < n; i++) {
                if(s[i] == '2') {
                    s[i] = '1';
                    cu--;
                    break;
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') {
                    s[i] = '2';
                    cu++;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    puts(s);
}

