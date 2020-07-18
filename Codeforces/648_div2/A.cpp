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
	int n,m;
	cin>>n>>m;
	int rows[n];
	int cols[m];
	fo(i,n){rows[i]=0;}
	fo(i,m){cols[i]=0;}
	int val;
	fo(i,n){
		fo(j,m){
			cin>>val;	
			if(val==1){
				rows[i]=1;
				cols[j]=1;	
			}
		}	
	}
	int col=0;
	int row=0;
	fo(i,n){
		if(rows[i]==0){row++;}	
	}
	fo(i,m){
		if(cols[i]==0){col++;}	
	}
	int rem = min(col,row);
	if(rem%2){
		cout<<"Ashish"<<endl;	
	}
	else{cout<<"Vivek"<<endl;}
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
