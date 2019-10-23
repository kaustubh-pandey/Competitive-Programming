#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll constraint(ll a,ll b){
	if(a>b){
		return b;
	}
	return 0;
}
int main(){
	ll n,I;
	cin>>n>>I;
	vector<ll> a(n,0);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	
	//cout<<K<<endl;
	map<ll,ll> m;
	for(ll i=0;i<n;i++){
		m[a[i]]++;
	}
	int q = ceil(log(m.size())/log(2));
	if(n*q<=8*I){
		cout<<"0"<<endl;
		return 0;
	}
	ll K = (ll)1<<(8*I/n);
	ll num = constraint(m.size(),K);
	//cout<<"e"<<endl;
	vector<int> v;
	for(auto x : m){
		v.push_back(x.second);
	}
	if(num>0){
		ll max_c=0;
		ll i = 0;
		while(i<num){
			max_c+= v[i];
			i++;
		}
		ll count=max_c;
		ll total=max_c;
		while(i<v.size()){
			count+= v[i];
			count-= v[i-num];
			total+= v[i];
			if(count>max_c){
				max_c=count;
			}
			i++;
		}
		cout<<total-max_c<<endl;

	}
	else{
		cout<<0<<endl;
	}
return 0;
}