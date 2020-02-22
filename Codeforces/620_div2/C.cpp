#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define Fo(i,q,n) for(i=q;i<n;i++)
#define rFo(i,q,n) for(i=n-1;i>=q;i--)
#define fO(i,n,k) for(i=0;i<n;i+=k)
#define FO(i,q,n,k) for(i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
using namespace std;

int main(){
	int q;
	cin>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		ll t_l=m,t_h=m;
		ll t_init=0;
		int i;
		bool flag = true;
		vector<vector<ll> >g;
		ll t,r,s;
		fo(i,n){
			cin>>t>>r>>s;
			g.push_back({t,r,s});
		}
		ll goal=0;
		fo(i,n){
			t=g[i][0];
			r=g[i][1];
			s=g[i][2];
			int amt = t-t_init;
			if(t_l-amt>s || t_h+amt<r){
				flag=false;
				break;
			}
			t_l = max(t_l-amt,r);
			t_h = min(t_h+amt,s);
			t_init=t;
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}