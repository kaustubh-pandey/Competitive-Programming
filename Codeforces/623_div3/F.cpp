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

int main(){
	int n;
	cin>>n;
	int a[n];
	int v[n];
	fo(i,n){
		cin>>a[i];
	}
	fo(i,n){
		cin>>v[i];
	}
	ll res=0;
	fo(i,n){
		Fo(j,i+1,n){
			ll xi = min(a[i],a[j]);
			ll xj=max(a[i],a[j]);
			ll vi,vj;
			if(xi == a[i]){
				vi = v[i];
				vj=v[j];
			}
			else{
				vi = v[j];
				vj=v[i];
			}
			if((vj-vi==0) || ((double)(xj-xi)/(vj-vi)>0)){
				res+=abs(xj-xi);
			}
		}
	}
	cout<<res<<endl;
	return 0;
}