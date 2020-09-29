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
#define endl "\n"
#define Endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
//const int N=2e5;
//int arr[N+1];

int subTree(int src,int parent,vector<int> g[],int subtree[]){
	for(auto x:g[src]){
		if(x==parent){continue;}
		subtree[src]+= subTree(x,src,g,subtree);	
	}
	subtree[src]+=1;
	return subtree[src];
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> g[n+1];
		int src,tar;
		fo(i,n-1){
			cin>>src>>tar;
			g[src].pb(tar);
			g[tar].pb(src);	
		}
		int m;
		cin>>m;
		vector<ll> fact(m,0);
		fo(i,m){
			cin>>fact[i];	
		}
		sort(fact.rbegin(),fact.rend());
		if(m<n-1){
			fo(q,n-1-m){
				fact.pb(1);	
			}	
		}
		else if(m>n-1){
			ll pro=1;
			fo(q,m-n+2){
				pro = (1LL*pro*fact[q])%MOD;	
			}
			fact.erase(fact.begin(),fact.begin()+m-n+2);
			fact.insert(fact.begin(),pro);	
		}
		//cout<<fact.size()<<endl;
		//cout<<n-1<<endl;
		int subtree[n+1];
		memset(subtree,0,sizeof(subtree[0])*(n+1));
		subTree(1,-1,g,subtree);
		vector<ll> mul;
		Fo(i,2,n+1){
			mul.pb((subtree[i]*1LL*(n-subtree[i])));	
		}
		sort(mul.rbegin(),mul.rend());
		ll ans = 0;
		fo(i,n-1){
			ans= (ans+(1LL*(mul[i]%MOD)*fact[i])%MOD)%MOD;
		}
		cout<<ans<<endl;				
	}
	return 0;
}
