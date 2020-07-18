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
		int n,k;
		cin>>n>>k;
		int a;
		int mxm = INT_MIN;
		bool flag = false;
		unordered_map<int,int> m;
		fo(i,n){
			cin>>a;
			mxm=max(mxm,a);
			m[a]++;	
			if(k==a){flag=true;}
		}
		if(!flag){
			cout<<"no"<<endl;	
		}
		else if(mxm==k && n>1 && m[k]==1){
			cout<<"no"<<endl;		
		}
		else{
			cout<<"yes"<<endl;	
		}	
	}
	return 0;
}
