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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		ll pos = n/2;
		ll val = m/pos;
		ll last=val;
		if(m%pos){
			last = val+m%pos;
		}
		if(n%2){
			cout<< (ll)((ll)2*(ll)((ll)(pos-1)*(ll)val) + (ll)(1+(n%2))*(ll)last)<<endl;
		}
		else{
			if(n==2){
				cout<<val<<endl;
			}
			else{
				cout<<(ll)((ll)2* (ll)((ll)(pos-2)*(ll)val) + (ll)((ll)2*(last+val))) <<endl;
			}
		}	
	}
	return 0;
}