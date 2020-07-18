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
bool isPower2(ll n){
	int count=0;
	while(n){
		if(n&1){
			count++;	
		}
		n = n>>1;	
	}
	if(count==1){return true;}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(a%b==0 || b%a==0){
			ll val;
			if(a>b){
				val = a/b;
			}
			else if(b>a){
				val = b/a;
			}
			else{
				val=0;	
			}
			if(val==0){
				cout<<val<<endl;
				continue;	
			}
			if(val&1 || !isPower2(val)){
				cout<<"-1"<<endl;
				continue;	
			}
			ll p=0;
			while((val&1)==0){
				val = val>>1;
				p++;	
			}
			//cout<<p<<endl;
			ll moves=0;
			ll tmp = (ll)p/3;
			moves+= (ll)p/3;
			p = p-(tmp*3);
			tmp = (ll)p/2;
			moves+= (ll)p/2;
			p = p-(tmp*2);
			moves+=p;
			cout<<moves<<endl;
		}
		else{
			cout<<"-1"<<endl;
			}
	}
	return 0;
}	
