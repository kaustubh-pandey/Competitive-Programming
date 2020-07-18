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
const int N=2e5;
int arr[N+1];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        int a[n];
        fo(i,n){
			cin>>a[i];	
		}
		int inc=0;
		int dec=0;
		int count=0;
		Fo(i,1,n){
			if(a[i]>a[i-1]){
				dec=0;
				inc++;
				if(inc==4){
					count++;
					inc=0;	
				}	
			}
			else if(a[i]<a[i-1]){
				inc=0;
				dec++;
				if(dec==4){
					count++;
					dec=0;	
				}	
			}
		}
        cout<<"Case #"<<z<<": "<<count <<endl;
    }
	return 0;
}
