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
	int t;
	cin>>t;
	while(t--){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b)==0){
			cout<<(int)(y-x)/(a+b)<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}