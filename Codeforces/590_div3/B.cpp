#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
bool check(vector<int> a,int k){
	for(int i=0;i<a.size();i++){
		if(a[i]==k){
			return true;
		}
	}
	return false;
}
int32_t main()
{
	/*
	int t;
	cin>>t;
	while(t--){
	
	}
	*/
	int n,k;
	cin>>n>>k;
	vector<int> v;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(check(v,tmp)){
			continue;
		}
		v.pb(tmp);
		if(v.size()>k){
			v.erase(v.begin());
		}
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[v.size()-i-1]<<" \n"[i==v.size()-1];
	}
	return 0;
}