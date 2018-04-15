#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll count(ll a[],ll n){
	ll c0=0;
	for(ll i=0;i<n;i++){
		if(a[i]>0){c0++;}
	}
	return c0;
}
int main(){
	ll n;
	cin>>n;
	ll h[n];
	if(n<=(1<<10)){
		for(ll i=0;i<n;i++){
			cin>>h[i];
		}
		ll q,x,y;
		cin>>q;
		for(ll i=0;i<q;i++){
			cin>>x>>y;
			//cout<<x<<" "<<y<<endl;
			for(ll j=0;j<n;j++){
				if((j&x)==j){
					h[j]-=y;
				}
			}
			cout<<count(h,n)<<endl;
		}
	}
	else{
		ll c0=0;
		for(ll i=0;i<n;i++){
			cin>>h[i];
			if(h[i]>0){c0++;}
		}
		ll q,x,y;
		cin>>q;
		for(ll i=0;i<q;i++){
			cin>>x>>y;
			//cout<<x<<" "<<y<<endl;
			for(ll j=0;j<n;j++){
				if((j&x)==j){
					h[j]=0;
					c0--;
				}
			}
			cout<<c0<<endl;
		}
	}
	return 0;
}