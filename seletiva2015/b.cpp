#include <cstdio>
#include <string>
typedef long long ll;

using namespace std;

bool palin(string s){
	int k = s.length();
	for(int i = 0; i < k/2; i++)
		if(s[i] != s[k-i-1]) return false;

	return true;
}

int main(){

	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		bool blank = false;
		for(ll i = 2; i <= 16; i++){
			ll aux = n;
			string num;
			while(aux){
				num += aux%i;
				aux /= i;
			}
			if(palin(num)){
				if(blank) printf(" ");
				blank = true;
				printf("%lld",i);		
			} 
		}
		if(!blank) printf("-1");
		printf("\n");
	}
}
