#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int ata, def, i, aux;
	vector<int> va, vd;

	while(scanf("%d %d", &ata, &def) && ata != 0){

		for(i = 0; i < ata; i++){
			scanf("%d", &aux);
			va.push_back(aux);
		}

		for(i = 0; i < def; i++){
			scanf("%d", &aux);
			vd.push_back(aux);
		}

		sort(va.begin(), va.end());
		sort(vd.begin(), vd.end());

		if(va[0] >= vd[1]) printf("N\n");

		else printf("Y\n");

		va.clear();
		vd.clear();
	}	
}