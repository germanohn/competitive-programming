#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// o crivo de erastotenes pode ser usado de duas formas:
// 1: usa um vetor de booleanos p que é false se i é 
// um numero primo
// 2: usa tambem um vetor prime mas prime[i] guarda o maior
// primo que divide i

// 1
void sieve () {
    p[1] = true;
    for (int i = 2; i < sieve_size; i++) {
        if (!p[i]) 
            for (int j = i*i; j < sieve_size; j += i) 
               p[j] = true; 
    }
}

// 2
void sieve () {
    for (int i = 2; i < sieve_size; i++) {
        if (!p[i])
            for (int j = i; j < sieve_size; j += i)
                p[j] = i;
    }
}

int main () {

}

