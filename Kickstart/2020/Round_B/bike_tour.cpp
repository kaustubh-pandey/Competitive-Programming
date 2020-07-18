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
	for(int z=1;z<=t;z++){
		int n;
		cin>>n;
		int a[n];
		fo(i,n){
			cin>>a[i];
		}
		int count=0;	
		Fo(i,1,n-1){
			if(a[i]>a[i-1] &&  a[i]>a[i+1]){
					count++;
			}
		}
		cout<<"Case #"<<z<<": "<<count<<endl;
	}
	return 0;
}
