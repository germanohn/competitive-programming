#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	vector<pair<int, int> > e;
	vector<pair<int, int> > r;

	int n;
	scanf("%d", &n);

	while(n--){
		int x, y;
		scanf("%d %d", &x, &y);

		if(x > 0)
			r.push_back(make_pair(x, y));
		else
			e.push_back(make_pair(-x, y));
	}

	sort(r.begin(), r.end());
	sort(e.begin(), e.end());

	int topr, tope;
	topr = r.size();
	tope = e.size();

	int mini = min(topr, tope);

	int soma = 0;
	if(topr == tope){
		for(int i = 0; i < mini; i++){
			soma += r[i].second + e[i].second;
		}
	}
	else if(topr > tope){
		for(int i = 0; i < mini + 1; i++)
			soma += r[i].second;	
		for(int i = 0; i < mini; i++)
			soma += e[i].second;
		
	}
	else if(topr < tope){
		for(int i = 0; i < mini + 1	; i++)
			soma += e[i].second;	
		for(int i = 0; i < mini; i++)
			soma += r[i].second;
	}

	printf("%d\n", soma);
}