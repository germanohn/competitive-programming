#include <bits/stdc++.h>

using namespace std;

struct pais{
	int id;
	int med;
} v[105];

bool comp(pais i, pais j){
	if(i.med > j.med) return true;
	if(i.med == j.med) return (i.id < j.id);
	return false;
}

int main(){
	
	int n,m;
	int o,p,b;

	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++) v[i+1].id = i+1;

	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&o,&p,&b);
		v[o].med++;
		v[p].med++;
		v[b].med++;
	}

	sort(v+1,v+n+1,comp);

	for(int i = 0; i < n; i++){
		printf("%d ",v[i+1].id);
	}
	printf("\n");

}