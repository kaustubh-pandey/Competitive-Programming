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
		unordered_map<int,bool> m;
		fo(i,n){
			cin>>a[i];
			m[a[i]]=true;	
		}
		//brute force
		vector<int> poss;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				poss.push_back(a[i]^a[j]);	
			}
		}
		sort(poss.begin(),poss.end());
		int ans=-1;
		for(int p:poss){
			//cout<<p<<endl;
			if(p>0){
				int flag=0;
				for(int i=0;i<n;i++){
					//cout<<(p^a[i])<<" "<<m[(p^a[i])]<<endl;
					if(m[p^a[i]]==false){
						flag=1;
						break;	
					}	
				}
				if(!flag){ans=p;break;}	
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
