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
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		int mat[n][m];
		fo(i,n){
			fo(j,m){
				mat[i][j]=0;	
			}	
		}
		int cols[m];
		fo(i,m){cols[i]=b;}
		bool flag=false;
		fo(i,n){
			int count=a;
			fo(j,m){
				if(cols[j]>0){
					mat[i][j]=1;
					cols[j]--;
					count--;	
				}
				if(count==0){break;}	
			}
			if(count!=0){flag=true;break;}	
		}
		fo(i,n){
				fo(j,m){
					cout<<mat[i][j];	
				}
				cout<<endl;	
			}
		bool flag2=false;
		fo(i,m){
			if(cols[i]!=0){flag2=true;break;}	
		}
		if(!flag && !flag2){
			cout<<"YES"<<endl;
			fo(i,n){
				fo(j,m){
					cout<<mat[i][j];	
				}
				cout<<endl;	
			}	
		}
		else{
			cout<<"NO"<<endl;	
		}	
	}
	return 0;
}
