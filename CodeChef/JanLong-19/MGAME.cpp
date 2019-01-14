#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,p;
		scanf("%lld %lld",&n,&p);
		ll r=n%((ll)n/2+1);
		ll res=(p-r)*(p-r)+(p-n)*(p-r)+(p-n)*(p-n);
		if(n<=2){
			res=p*p*p;
		}
		printf("%lld\n",res);
	}
	return 0;
}