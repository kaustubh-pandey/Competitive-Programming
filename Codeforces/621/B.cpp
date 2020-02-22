#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n,0);
		fo(i,n){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		ll hops=0;
		if(binary_search(a.begin(),a.end(),d)){
			cout<<1<<endl;
		}
		else if(a[n-1]>d){
			cout<<2<<endl;
		}
		else{
			cout<<(d/a[n-1])+((d%a[n-1])?1:0)<<endl;
		}
	}
	return 0;
}