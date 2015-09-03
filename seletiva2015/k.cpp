#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#define MAXN 2005
#define eps 0

using namespace std;

double v[MAXN];

double area(double a, double b, double c){
	double ro = (a+b+c)/2;
	return sqrt(ro*(ro-a)*(ro-b)*(ro-c));
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	 	for(int i = 0; i < n; i++)
			scanf("%lf",&v[i]);
		sort(v,v+n);
		double ans = INT_MAX;
		for(int i = 0; i < n-2; i++){
			for(int j = i+1; j < n-1; j++){
				int lo = j+1;
				int hi = n-1;
				double r1,r2,menor,maior;
				menor = v[j]-v[i];
				maior = v[i]+v[j];
				//printf("menor %lf maior %lf\n",menor,maior);
				r1 = r2 = INT_MAX;
				while(lo != hi){
					int mid = (lo+hi)/2;
					if(v[mid] - menor > eps)
						hi = mid;
					else
						lo = mid+1;
				}
				//printf("tripla r1 %lf %lf %lf\n",v[i],v[j],v[lo]);
				if(v[lo] - menor > eps && v[lo] - maior < eps)
					r1 = area(v[i],v[j],v[lo]);
				lo = j+1, hi = n-1;
				while(lo != hi){
					int mid = (lo+hi+1)/2;
					if(v[mid] - maior < eps)
						lo = mid;
					else
						hi = mid-1;
				}
				if(v[lo] - menor > eps && v[lo] - maior < eps)
					r2 = area(v[i],v[j],v[lo]);

				//printf("tripla r2 %lf %lf %lf\n",v[i],v[j],v[lo]);
				//printf("r1 %lf r2 %lf\n",r1,r2);
				ans = min(ans,min(r1,r2));
			}
		}
		if(ans == INT_MAX){
			printf("-1\n");
			continue;
		}
		printf("%.2lf\n",ans);
	}

}
