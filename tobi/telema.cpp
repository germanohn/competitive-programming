#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
vector<int> vp;

int main(){

	int n, l, menor, i;
	scanf("%d %d", &n, &l);

	for(i = 1; i <= n; i++){
		v.push_back(0);
		vp.push_back(0);
	}

	while(l > 0){

		int a;
		scanf("%d", &a);
		menor = 0;
		for(i = 1; i < n; i++){
			if(v[i] < v[menor])
				menor = i;	
		}
		v[menor] += a;
		vp[menor] += 1;
		l--;
	}

	for(i = 0; i < n; i++) printf("%d %d\n", i+1, vp[i]);

	return 0;	
}