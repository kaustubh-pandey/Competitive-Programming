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
		int n,a,b;
		cin>>n>>a>>b;
		string stub = "";
		fo(i,b){
			stub+= 'a'+i;	
		}
		int left  = a-stub.size();
		fo(i,left){
			stub+= stub[i];	
		}
		int left2 = n - stub.size();
		fo(i,left2){
			stub+=stub[i];	
		}
		cout<<stub<<endl;	
	}
	return 0;
}
