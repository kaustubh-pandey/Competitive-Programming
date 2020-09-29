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
ll min(ll a,ll b){
	if(a<b){return a;}
	return b;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	fo(z,t){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1,0);
		Fo(i,1,n+1){
			cin>>a[i];	
		}
		if(m>=n-1){
			cout<<"Case #"<<z+1<<": "<<0<<endl;
			continue;			
		}
		ll dp[n+1];
		fo(i,m+2){
			dp[i]=0;	
		}
		Fo(i,m+2,n+1){
			ll tmp = LLONG_MAX;
			Fo(j,1,m+1){
				if(dp[i-j]!=-1 && a[i-j]!=0){
					tmp = min(tmp,dp[i-j]+a[i-j]);		
				}
			}
			if(tmp==LLONG_MAX){
				dp[i]=-1;	
			}
			else{
				dp[i]=tmp;		
			}
		}
		cout<<"Case #"<<z+1<<": "<<dp[n]<<endl;				
	}
	return 0;
}

/*
 * NOt good enough, got timeout O((n-m)*m) gives max of 10^11
 * */
