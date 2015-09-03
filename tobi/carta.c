#include <cstdio>
#include <algorithm>

#define MAX 45005

int main(){

	int n, m, v[MAX], achei, i, dis, lo, hi, mid, atual = 0, a;

	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	atual = 0;
	dis = 0;
	while(m > 0){
		scanf("%d", &a);
	
		lo = 0;
		hi = n - 1;
		achei = 0;
		
		while(lo <= hi && !achei){
			
			mid = (lo + hi)/2;
			
			if(a == v[mid]){
				dis += abs(mid - atual);
				atual = mid;
				achei = 1;
				
			}
			if(a < v[mid]) hi = mid - 1;

			if(a > v[mid]) lo = mid + 1;
		}	
		m--;
	}
	printf("%d\n", dis);
}
