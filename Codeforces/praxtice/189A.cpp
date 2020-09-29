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


int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int coins[3] = {a,b,c};
	int dp[n+1];
	fo(i,n+1){
		dp[i]=INT_MIN;	
	}
	dp[0]=0;
	Fo(i,1,n+1){
		for(int j=0;j<3;j++){
			if(coins[j]<=i){
				if(dp[i-coins[j]]!=INT_MIN){
					dp[i] = max(dp[i],dp[i-coins[j]]+1);		
				}
			}	
		}
	}
	//printarr(dp,n+1);
	if(dp[n]>0){
		cout<<dp[n]<<endl;	
	}
	else{
		cout<<0<<endl;	
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
