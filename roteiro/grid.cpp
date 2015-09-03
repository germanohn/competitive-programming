#include <cstdio>
#define MAX 27

using namespace std;

int n, l[MAX], r[MAX], aux[MAX];

int main(){

	while(scanf("%d", &n) != EOF){
		
		for(int i = 1; i <= n; i++) scanf("%d", &l[i]);

		for(int i = 1; i <= n; i++) scanf("%d", &r[i]);

		for(int i = 1; i <= n; i++) aux[r[i]] = i;

		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < n; j++){
				if(aux[l[j]] > aux[l[j+1]]){
					int au;
					au = l[j];
					l[j] = l[j+1];
					l[j+1] = au;
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}
}