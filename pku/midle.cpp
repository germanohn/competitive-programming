#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(){

	int n, i, a;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v[n/2]);
}
