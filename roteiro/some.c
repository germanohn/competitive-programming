#include <stdio.h>

int main(){

	int soma, sum, p;
	char l[100], m[100];

	while(scanf("%s %s", l, m) && l != "0" && m != "0"){
		soma = 0;
		sum = 0;
		for(i=0; l[i]!=" "; i++){
			
			if(l[i] >= "A" && l[i] <= "Z"){
				soma = soma + l[i] - 64;
			}
			else soma = soma + l[i];
		}


		for(j=i+1; l[i]!=\0; j++){
			
			if(l[j] >= "A" && l[j] <= "Z"){
				sum = sum + l[j] - 64;
			}
			else sum = sum + l[j];
		}

		p = soma + sum;
		printf("")
	}


	
	return 0;	

}