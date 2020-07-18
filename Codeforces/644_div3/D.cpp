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
int smallestFactor(int n,int k){
	int lower = (n+k-1)/k;
	if(n%2==0){
		if(lower<=2){return 2;}	
	}
	for(int i=max(lower,3);i<=n/2;i++){
		if(n%i==0){
			return i;	
		}	
	}
	return n;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k>=n){
			cout<<1<<endl;
			continue;	
		}
		int f = smallestFactor(n,k);
		cout<<f<<endl;
	}
	return 0;
}
