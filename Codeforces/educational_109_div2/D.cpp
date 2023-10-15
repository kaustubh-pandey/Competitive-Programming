#include<bits/stdc++.h>
#define ll long long
#define xll __int128
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
#define TIK auto start = chrono::high_resolution_clock::now();
#define TOK auto end = chrono::high_resolution_clock::now();double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();time_taken *= 1e-9;cerr << "Time taken:" << fixed << time_taken << setprecision(9);cerr << " sec" << endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
//const int N=2e5;
//int arr[N+1];

ll min(ll a,ll b){
	if(a<b){
		return a;
	}
	return b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int x;
		cin>>x;
		vector<int> a;
		vector<int> b;
		int d;
		fo(i,x){
			cin>>d;
			if(d==1){
				a.pb(i);
			}
			else{
				b.pb(i);
			}
		}
		int n = a.size();	
		int m = b.size();
		vector<vector<ll> > dp(n+1,vector<ll>(m+1,0));
		fo(i,n+1){
			dp[i][0]=INT_MAX;  //Assign person to no chair, impossible
		}
		dp[0][0]=0;	//No person to assign to chair, cost 0
		Fo(i,1,n+1){
			Fo(j,1,m+1){
				dp[i][j] = min(abs(a[i-1]-b[j-1])+dp[i-1][j-1],dp[i][j-1]);
				/*
				Actually we want to make min of above as well as dp[i][j-2],dp[i][j-3]
				and so on. But dp[i][j-1] already takes care of that (ITS THE MIN!). So
				no need
				*/
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!
: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/