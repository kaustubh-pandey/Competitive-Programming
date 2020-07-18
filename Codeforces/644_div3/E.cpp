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
		int n;
		cin>>n;
		int a[n][n];
		fo(i,n){
			string tmp;
			cin>>tmp;
			fo(j,n){
				a[i][j]=tmp[j]-'0';	
			}	
		}
		bool flag= true;
		fo(i,n){
			fo(j,n){
				if(a[i][j]==1 && i+1<n && j+1<n){
					if(a[i+1][j]==0 && a[i][j+1]==0){
						//cout<<i<<" "<<j<<endl;
						flag=false;
						break;	
					}
				}	
			}
			if(!flag){break;}	
		}
		if(flag){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}	
	}
	return 0;
}
