#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll a[n],v[n];
		
		for(ll i=0;i<n;i++){
			scanf("%lld",&a[i]);
			v[i]=0;
		}
		ll sum;
		for(ll i=0;i<n;i++){
			sum=0;
			if(i>0){v[i-1]++;}
			for(ll j=i-2;j>=0;j--){
				sum+=a[j+1];
				if(sum>a[i]){break;}
				v[j]++;
			}
			if(i<n-1){v[i+1]++;}
			sum=0;
			for(ll j=i+2;j<n;j++){
				sum+=a[j-1];
				if(sum>a[i]){break;}
				v[j]++;	
			}
		}
		for(ll i=0;i<n;i++){
			printf("%lld ",v[i]);
		}
		printf("\n");

	}

	return 0;
}