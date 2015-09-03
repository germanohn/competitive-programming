#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> mapa;

long long dolar(long long n){

	if(n == 0) return n;

	if(mapa.find(n) != mapa.end()) return mapa[n];

	long long r1, r2;

	r1 = n;
	r2 = dolar(n/2) + dolar(n/3) + dolar(n/4);

	mapa.insert(make_pair(n, max(r1, r2)));
	return mapa[n];
}

int main(){

	long long n;

	while(scanf("%lld", &n) != EOF)
		printf("%lld\n", dolar(n));
}