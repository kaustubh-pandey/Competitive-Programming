#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;
ll lcm(ll a,ll b){
	return a*b/(__gcd(a,b));	
}
ll gcd(vector<ll> a){
	ll res = a[0];
	for(auto x:a){
		res = __gcd(x,res);	
	}
	return res;	
}
int main(){
	int n;
	cin>>n;
	vector<ll> a(n);
	fo(i,n){
		cin>>a[i];	
	}
	//precalculate gcd like prefix
	vector<ll> prefix(n);
	vector<ll> suffix(n);
	prefix[0]=a[0];
	suffix[n-1]=a[n-1];
	ll gc = a[0];
	ll gc_back = a[n-1];
	Fo(i,1,n){
		gc = __gcd(gc,a[i]);
		prefix[i]=gc;
		gc_back= __gcd(gc_back,a[n-i-1]);
		suffix[n-i-1] = gc_back;	
	}
	vector<ll> arr(n);
	arr[0] = lcm(a[0],suffix[1]);
	Fo(i,1,n-1){
		arr[i] = lcm(a[i],__gcd(prefix[i-1],suffix[i+1]));	
	}
	arr[n-1] = lcm(a[n-1],prefix[n-2]);
	cout<<gcd(arr)<<endl;
	return 0;
	
}
