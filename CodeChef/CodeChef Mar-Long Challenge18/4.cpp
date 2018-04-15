#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll a[],ll k,ll n){
	ll s=0;
	for(ll i=0;i<n;i++){
		//cout<<ceil(a[i]/k)<<" s"<<endl;
		s+=ceil(a[i]*1.0/k);
	}
	return s;
}
ll sum(ll a[],ll n){
	ll s=0;
	for(ll i=0;i<n;i++){
		s+=a[i];
	}
	return s;
}
int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n,h;
		scanf("%lld %lld",&n,&h);
		ll a[1000000];
		for(ll i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		ll k=(int)(sum(a,n)/h);
		//cout<<k<<endl;
		if(k==0){
			k=1;
		}
		ll s=check(a,k,n);
		//cout<<s<<endl;
		while(s>h){
			k+=(int)(s/h);
			//cout<<k<<endl;
			s=check(a,k,n);
		}
		printf("%lld\n",k);
	}

	return 0;
}