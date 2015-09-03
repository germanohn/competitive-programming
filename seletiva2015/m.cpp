#include <cstdio>
#include <vector>
using namespace std;
int v[100005];
int vans[100005];

vector <int> ansv;

void proc(int i){

	if(v[i] == 0 || v[i] == -1) return;
	else{
		v[i] = 0;
		ansv.push_back(i);
		v[i+1] *= -1;
		v[i-1] *= -1;
		proc(i+1);
		proc(i-1);
	}
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			char c;
			scanf(" %c",&c);
			if(c == 'B') v[i] = -1;
			else v[i] = 1;
		}
		v[0] = 0;
		v[n+1] = 0;
		bool ans = true;
		for(int i = 1; i <= n; i++)
			proc(i);
		for(int i = 1; i <= n; i++)
			if(v[i] == -1) ans = false;

		if(ans){
			printf("Y\n");
			for(int i = 0; i < ansv.size(); i++)
				printf("%d%c",ansv[i],i == ansv.size()-1 ? '\n' : ' ');
		}
		else
			printf("N\n");
		ansv.clear();
	}
}
