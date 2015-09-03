#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int c,d,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&c,&d);
		int ans;
		if(c == 0 && d!= 0)
			ans = pow(10,d);
		else if(d == 0 && c != 0)
			ans = pow(26,c);
		else if(c == d && c == 0)
			ans = 0;
		else
			ans = pow(26,c)*pow(10,d);
		printf("%d\n",ans);
	}
}
