#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main () {
    ll n;

    cin >> n;
    char c = 'A';
    if(n!=1){
        if(n%2==0) cout << n << endl;
        else cout << n << endl;
}
    //printf("%dA %dA\n", 1, n);

    if(n%2==0){
        for(int i = 0; i<n/2;i++){
            printf("%dA %dA\n", 2*i+1, 2*i+2);

        }
        for(int i = 0; i<n/2;i++){
            printf("%dB %dB\n", 2*i+1, 2*i+2);

        }
    }

    if(n==1){
        cout << 2 << endl;
        printf("0X %dA\n", 1);
        printf("0X %dB\n", 1);

    }
    else if(n%2==1){


        for(int i = 1; i<n/2;i++){
            printf("%dA %dA\n", 2*i+1, 2*i+2);

        }
        for(int i = 1; i<n/2;i++){
            printf("%dB %dB\n", 2*i+1, 2*i+2);

        }
        printf("%dA %dA\n", 1, 2);
        printf("%dB %dB\n", 2, n);
        printf("%dB %dA\n", 1, n);
    }

    //cout << a*a << endl;
}
