#include <cstdio>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
set<string> alie;

int main(){

	int n;
	while(scanf("%d", &n) && n != 0){

		char s[105];
		string st;
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			st = s;
			sort(st.begin(), st.end());
			alie.insert(st);
		}

		printf("%lu\n", alie.size());
		alie.clear();
	}
}