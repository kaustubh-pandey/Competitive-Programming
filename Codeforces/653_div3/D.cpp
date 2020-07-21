#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
//const int N=2e5;
//int arr[N+1];

void print() 
{ 
    cout <<endl;
}
template <typename T, typename... Types> 
void print(T var1, Types... var2) 
{ 
    cout << var1 << " " ; 
  
    print(var2...) ; 
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		map<int,int> m;
		fo(i,n){
			cin>>a[i];
		}
		int flag=0;
		int mx = 0;
		fo(i,n){
			if(a[i]%k){flag=1;m[a[i]]++;mx++;}	
		}
		if(!flag){cout<<0<<endl;continue;}
		
		ll x0=0;
		while(mx>0){
			ll fr=0;
			unordered_map<ll,bool> visited;
			for(auto x:m){
				if(x.second==0){continue;}
				ll val = ((ll)(x.first+x0+k-1)/k)*k - x.first;
				fr= max(fr,val);
				if(!visited[val]){
					m[x.first]--;
					mx--;
					visited[val]=true;	
				}	
			}
			x0 = fr+1;
			//cout<<x0<<endl;					
		}
		cout<<x0<<endl;
	}
	return 0;
}
