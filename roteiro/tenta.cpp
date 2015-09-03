#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vp;
int n;

int main(){

	while(scanf("%d", &n) && n != 0){

		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			vp.push_back(a);
		}
		sort(vp.begin(), vp.end());
		
		for(int i = 0; i < n; i++) printf("%d ", vp[i]);
		printf("\n");

		while(next_permutation(vp.begin(), vp.end())){
			for(int i = 0; i < n; i++) printf("%d ", vp[i]);	
			printf("\n");		
		}
		printf("\n");
		vp.clear();
	}
}