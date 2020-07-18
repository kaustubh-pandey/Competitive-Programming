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
		char arr[n];
		fo(i,n){
			arr[i]='a';	
		}
		int curr=1;
		int len=0;
		int start=1;
		while(curr<=k){
			start=curr;
			len++;
			curr+=len;	
		}
		arr[n-len-1]='b';
		arr[n-k+start-1]='b';
		string res="";
		fo(i,n){
			res+=arr[i];	
		}
		cout<<res<<endl;	
	}
	return 0;
}
