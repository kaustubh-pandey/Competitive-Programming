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
		int a[n];
		fo(i,n){
			cin>>a[i];
		}
		int moves=1;
		int alice=a[0];
		int bob=0;
		int l=1;
		int r=n-1;
		int prevalice=a[0];
		int prevbob=0;
		while(l<=r){
			if(moves%2){
				//bob
				int right=0;
				while(r>=l && right<=prevalice){
					right+= a[r];
					r--;
				}
				prevbob = right;
				bob+=prevbob;
			}
			else{
				//alice
				int left=0;
				while(l<=r && left<=prevbob){
					left+= a[l];
					l++;
				}
				prevalice = left;
				alice+=prevalice;
			}
			moves++;
		}
		cout<<moves<<" "<<alice<<" "<<bob<<endl;
	}
	return 0;
}