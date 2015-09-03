#include <stdio.h>

int main(){

	int n, r, m[10010], a, i, maior, um;

	while(scanf("%d %d", &n, &r) != EOF){

		um = 0;
		for(i=1; i<10010; i++) m[i] = 0;

		while(r > 0){
			
			scanf("%d", &a);
			
			m[a]++;
			r--;
		}

		for(i=1; i<=n; i++){
			if(m[i] == 0){
				printf("%d ", i);
				um = 1;	
			} 

		}
		if(!um) printf("*");
		
		printf("\n");
	}
	return 0;
}