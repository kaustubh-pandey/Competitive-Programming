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
	string s;
	cin>>s;
	int n=s.size();
	int dp[n+1][4];
	memset(dp,0,sizeof(dp[0][0])*(n+1)*4);
	string p="QAQ";
	fo(i,4){dp[0][i]=0;}
	fo(i,n+1){dp[i][0]=1;}
	Fo(i,1,n+1){
		Fo(j,1,4){
			dp[i][j] = (s[i-1]==p[j-1])?dp[i-1][j-1]:0;
			dp[i][j]+= dp[i-1][j];	
		}	
	}
	cout<<dp[n][3]<<endl;
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
