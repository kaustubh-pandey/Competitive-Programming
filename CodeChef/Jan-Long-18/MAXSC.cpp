#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll find(ll a[][701],int i,ll k,int n){
	for(int j=n-1;j>=0;j--){
		if(a[i][j]<k){
			return a[i][j];
		}
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a[701][701];
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%lld",&a[i][j]);
			}
			sort(begin(a[i]),begin(a[i])+n);
		}
		ll k=a[n-1][n-1];
		ll x;
		ll sum=k;
		for(int i=n-2;i>=0;i--){
			x=find(a,i,k,n);
			k=x;
			if(x!=-1){
				sum+=x;
			}
			else{ sum=-1;break;}
		}
		printf("%lld\n",sum);

	}
	return 0;
}