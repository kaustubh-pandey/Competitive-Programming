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

ll max(ll a,ll b){
	if(a>b){return a;}
	return b;	
} 
int main(){
	int n,w;
	cin>>n>>w;
	vector<int> val(n,0);
	vector<int> wt(n,0);
	fo(i,n){
		cin>>wt[i];
		cin>>val[i];	
	}
	ll dp[n+1][w+1];
	fo(i,n+1){
		fo(j,w+1){
			if(i==0||j==0){dp[i][j]=0;continue;}
			//cout<<j<<" "<<wt[i-1]<<endl;
			if(j>=wt[i-1]){
				//cout<<"skna"<<endl;
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);	
			}
			else{
				dp[i][j] = dp[i-1][j];		
			}
		}	
	}
	//fo(i,n+1){
		//fo(j,w+1){
			//cout<<dp[i][j]<<" ";	
		//}
		//cout<<endl;	
	//}
	cout<<dp[n][w]<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
