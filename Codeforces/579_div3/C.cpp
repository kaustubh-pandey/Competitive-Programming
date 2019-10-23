#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll GCD(vector<ll> a){
	ll g = a[0];
	for(int i=1;i<a.size();i++){
		g=gcd(g,a[i]);
	}
	return g;
}
int main(){
	int n;
	cin>>n;
	vector<ll> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll g = GCD(a);
	map<ll,int> m;
	while(g%2==0){
		g=g/2;
		m[2]++;
	}
	for(ll i=3;i*i<=g;i+=2){
		while(g%i==0){
			g=g/i;
			m[i]++;
		}
	}
	if(g>1){
		m[g]++;
	}
	ll pro=1;
	for(auto x:m){
		if(x.second!=0){
			pro=pro*(x.second+1);
		}
		
	}
	cout<<pro<<endl;
	return 0;
}