#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define Fo(i,q,n) for(i=q;i<n;i++)
#define rFo(i,q,n) for(i=n-1;i>=q;i--)
#define fO(i,n,k) for(i=0;i<n;i+=k)
#define FO(i,q,n,k) for(i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n,0);
		int i;
		int mini=INT_MAX;
		int maxi=INT_MIN;
		fo(i,n){
			cin>>v[i];
		}
		int max_val=0;
		fo(i,n-1){
			if(v[i]!=-1 && v[i+1]!=-1){
				max_val=max(max_val,abs(v[i]-v[i+1]));
			}
		}
		fo(i,n){
			if(v[i]!=-1){
				if((i-1>=0 && v[i-1]==-1) || (i+1<n && v[i+1]==-1)){
					mini=min(v[i],mini);
					maxi=max(v[i],maxi);
				}
			}
		}
		int val = round((double)(maxi+mini)/2);
		if(val==-1){
			val=0;
		}
		int maxd=0;
		fo(i,n-1){
			int curr = (v[i]==-1)?val:v[i];
			int curr_ne = (v[i+1]==-1)?val:v[i+1];
			maxd=max(maxd,abs(curr-curr_ne));
		}
		cout<<max(max_val,maxd)<<" "<<val<<endl;
	}
	return 0;
}