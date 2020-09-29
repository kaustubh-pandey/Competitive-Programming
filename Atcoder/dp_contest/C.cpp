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

 
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	vector<int> b(n,0);
	vector<int> c(n,0);
	fo(i,n){
		cin>>a[i]>>b[i]>>c[i];	
	}
	
	vector< vector<int> > dp(n,vector<int>(3,0));
	dp[0][0]=a[0];
	dp[0][1]=b[0];
	dp[0][2]=c[0];
	fo(i,n){
		if(i==0){continue;}
		dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2] = max(dp[i-1][1],dp[i-1][0])+c[i];
	}
	cout<< max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
