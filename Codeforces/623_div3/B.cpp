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
		int a[n];
		int c[n];
		int p[m];
		fo(i,n){
			cin>>a[i];
			c[i]=a[i];
		}
		fo(i,m){
			cin>>p[i];
		}
		sort(p,p+m);
		sort(c,c+n);
		fo(i,n){
			fo(j,m){
				if(a[p[j]-1]>a[p[j]]){
					int tmp=a[p[j]-1];
					a[p[j]-1]=a[p[j]];
					a[p[j]]=tmp;
				}
			}
		}
		int flag=0;
		fo(i,n){
			if(a[i]!=c[i]){
				flag=1;
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}