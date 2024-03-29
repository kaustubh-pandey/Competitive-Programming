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
using namespace std;
const int MOD=998244353;
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

int main(){
	int n,q;
	cin>>n>>q;
	//n--;
	vector< pair<int,int> > v;
	fo(i,q){
		int a,b;
		cin>>a>>b;
		v.pb(mp(a,b));	
	}
	sort(v.begin(),v.end());
	ll dp[n+2];
	memset(dp,0,sizeof(dp[0])*(n+2));
	dp[0]=1;
	dp[1]=-1;
	//printarr(dp,n+1);
	//for(int i=1;i<=n;i++){
		//for(auto x:v){
			//if(x.F>i){break;}
			//for(int j=x.F;j<=min(x.S,i);j++){
				//dp[i] = (dp[i] +  dp[i-j])%MOD;
			//}	
		//}	
	//}
	for(int i=0;i<n;i++){
		if(i>=1){dp[i]=(dp[i]+dp[i-1])%MOD;}
		for(auto x:v){
			if(i+x.F<n){
				dp[i+x.F] = (dp[i+x.F] + dp[i])%MOD;	
			}
			if(i+x.S+1<n){
				dp[i+x.S+1] = (dp[i+x.S+1] - dp[i])%MOD;
				if(dp[i+x.S+1]<0){dp[i+x.S+1]+=MOD;}	
			}
		}
		//printarr(dp,n);	
	}
	
	//printarr(dp,n+1);
	cout<<dp[n-1]<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
