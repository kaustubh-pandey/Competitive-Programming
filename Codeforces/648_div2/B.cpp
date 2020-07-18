#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define read_arr(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define mp make_pair
#define F first
#define S second
using namespace std;
const int MOD=1000000007;
const int N=2e5;
int a[N];


void solve(){
	int n;
	cin>>n;
	int b[n];
	int c[n];
	fo(i,n){cin>>b[i];}
	fo(i,n){cin>>c[i];}
	bool flag=true;
	bool flag2= false;
	fo(i,n-1){
		if(c[i]!=c[i+1]){flag2=true;break;}	
	}
	if(!flag2){
		fo(i,n-1){
			if(b[i]>b[i+1]){flag=false;break;}	
		}	
	}
	if(flag){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
 ios::sync_with_stdio(false);
 cin.tie(0);
*/
