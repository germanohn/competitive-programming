#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

bool palin(int n, int t){

	string s, ss;

	for(int i = 0; i < t; i++){

		s += n%10 + '0';
		n = n/10;
	}

	for(int i = 0; i < t; i++)
		s += s[t-i-1];

	if(ss == s) return true;

	else return false;
}

int main(){

	char n[10];
	int num, i;

	i = 0;
	while(scanf(" %s", n)){
		
		int t = strlen(n);
		
		if(t == 1 && n[0] == '0')
			break;

		int pot = 1, num = 0;
		for(i = t-1; i >= 0; i--){

			num += pot*(n[i] - '0');
			pot *= 10; 
		}

		int op = 0;
		while(!palin(num + op, t)) op++;

		printf("%d\n", op);

	}
}