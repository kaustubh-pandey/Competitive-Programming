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
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;

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
//ceil of a/b
template <typename T>
T fceil(T a,T b){
    return (T)(a+b-1)/b;			
}
//const int N=2e5;
//int arr[N+1];
bool cmp( pair<pair<ll,ll>, ll> p1,pair<pair<ll,ll>, ll> p2){
	if(p1.F.S<p2.F.S){
		return true;	
	}
	else if(p1.F.S==p2.F.S){
		if(p1.F.F<p2.F.F){
			return true;	
		}
		return false;
	}
	return false;	
}
int binsearch(vector< pair<pair<ll,ll>, ll> > &v,int l,int r,ll start_time,ll id){
	if(l<=r){
		int mid = l+ (r-l)/2;
		if(v[mid].F.S==start_time){
			if(v[mid].S!=id){
				return mid;
			}
			else{
				if(mid-1>=0 && v[mid-1].F.S==start_time){
					return mid-1;
				}
				else if(mid+1<(int)v.size() && v[mid+1].F.S==start_time){
					return mid+1;	
				}
				return -1;	
			}	
		}
		else if(v[mid].F.S<start_time){
			return binsearch(v,mid+1,r,start_time,id);	
		}
		else if(v[mid].F.S>start_time){
			return binsearch(v,l,mid-1,start_time,id);	
		}
		return -1;	
	}
	return -1;
}
ll max(ll a,ll b){
	if(a>b){return a;}
	return b;	
} 
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	fo(z,t){
		int n;
		cin>>n;
		vector< pair<int,int> > v;
		int p,h;
		fo(i,n){
			cin>>p>>h;
			v.pb(mp(p,h));
		}
		sort(v.begin(),v.end());
		map<int,int> dp;
		int maxm = 0;
		for(int i=0;i<(int)v.size();i++){
			dp[v[i].F+v[i].S] = max(dp[v[i].F+v[i].S],dp[v[i].F]+v[i].S);
			dp[v[i].F] = max(dp[v[i].F],dp[v[i].F-v[i].S]+v[i].S);
			maxm = max({maxm,dp[v[i].F+v[i].S],dp[v[i].F]});	
		}
		cout<<"Case #"<<z+1<<": "<<maxm<<endl;	
	}
	return 0;
}
