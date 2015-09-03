#include <stdio.h>
#define MAX 100005

int procura(int v[], int lo, int hi, int num, int p){
	int mid;
	mid = (lo + hi)/2;

	if(lo > hi) return p;

	if(v[mid] == num){
		p = mid;
		return procura(v, lo, mid - 1, num, p);
	} 

	if(v[mid] < num) return procura(v, mid + 1, hi, num, p);

	if(v[mid] > num) return procura(v, lo, mid - 1, num, p);

}


int main(){

	int n, q, v[MAX], i, num, p = -1;

	scanf("%d %d", &n, &q);

	for(i = 0; i < n; i++) scanf("%d", &v[i]);

	while(q--){
		
		scanf("%d", &num);
		printf("%d\n", procura(v, 0, n-1, num, p));
	}	
	return 0;
}