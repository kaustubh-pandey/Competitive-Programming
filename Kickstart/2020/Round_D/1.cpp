#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define mp make_pair
#define F first
#define S second
using namespace std;
const int MOD=1000000007;
//const int N=2e5;
//int arr[N+1];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        int a[n];
        bool b[n];
        memset(b,false,sizeof(b));
        fo(i,n){
			cin>>a[i];
		}
		int maxm = INT_MIN;
		fo(i,n-1){
			if(a[i]>maxm && a[i]>a[i+1]){
				b[i]=true;	
			}
			maxm=max(a[i],maxm);
		}
		if(a[n-1]>maxm){
			b[n-1]=true;	
		}
		int count=0;
		fo(i,n){
			if(b[i]){count++;}	
		}
        cout<<"Case #"<<z<<": "<<count <<endl;
    }
	return 0;
}
