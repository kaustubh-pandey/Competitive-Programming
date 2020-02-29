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
int best(int n,int x,int y){
	if(x+y-n>0){
		return x+y-n+1;
	}
	return 1;
}
int worst(int n,int x,int y){
	int rank=1;
	if(n-x<=y-1){
		rank+=min(y-1,n-x);
	}
	if(n-y<=x-1){
		rank+=min(x-1,n-y);
	}
	int left = abs(y-1-n+x);
	return rank+left;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		cout<<best(n,x,y)<<" "<<worst(n,x,y)<<endl;
	}
	return 0;
}