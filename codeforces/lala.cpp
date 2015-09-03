#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	vector<pair<int, int> > r;
	vector<pair<int, int> > e;

	int n, i, cont_r = 0, cont_e = 0, soma = 0, a, b;

	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &a, &b);

		if(a > 0){
			r.push_back(make_pair(a, b));
			cont_r++;
			
		}

		else{
			e.push_back(make_pair(-a, b));
			cont_e++;
		}
	}

	sort(r.begin(), r.end());
	sort(e.begin(), e.end());
	for(i = 0; i < cont_e; i++) printf("%d ", e[i].second);

	printf("\n");
	for(i = 0; i < cont_r; i++) printf("%d ", r[i].second);

	printf("\n");	

	if(abs(cont_r - cont_e) <= 1){
		for(i = 0; i < cont_r; i++)
			soma += r[i].second;

		for(i = 0; i < cont_e; i++)
			soma += e[i].second;
	}
		
	else{
		if(cont_r < cont_e){
			for(i = 0; i < cont_r; i++)
				soma += r[i].second + e[i].second;
			soma += e[i].second;
		}

		else
			for(i = 0; i < cont_e; i++)
				soma += r[i].second + e[i].second;
			soma += r[i].second;

	}

	printf("%d\n", soma);
	
}