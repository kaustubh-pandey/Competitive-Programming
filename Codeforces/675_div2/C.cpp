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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		if(n==1){cout<<0<<endl;continue;}
		ll prefix[n];
		prefix[0] = s[0]-'0';
		Fo(i,1,n){
			prefix[i]= ((prefix[i-1]*10)%MOD + s[i]-'0')%MOD;
		}
		ll suffix[n];
		suffix[n-1] = s[n-1]-'0';
		ll pro=10;
		rFo(i,0,n-1){
			suffix[i] = (suffix[i+1]+ (pro*(s[i]-'0'))%MOD)%MOD;
			pro = (pro*10)%MOD;
		}
		//printarr(prefix,n);
		//printarr(suffix,n);
		rFo(i,0,n-1){
			suffix[i] = (suffix[i] + suffix[i+1])%MOD;
		}
		//printarr(suffix,n);
		ll ten[n+1];
		ten[0]=0;
		ll powe = 10;
		Fo(i,1,n+1){
			ten[i] = (ten[i-1] + powe)%MOD;
			powe = (powe*10)%MOD;
		}
		ll res=0;
		fo(i,n-1){
			ll num = prefix[i]%MOD;
			ll sum = num%MOD;
			if(i+2<n){
				ll zer = n-i-2;
				ll mul = ten[zer];
				sum = (sum + (mul * (num%MOD))%MOD)%MOD;
				sum = (sum+suffix[i+2])%MOD;
			}
			res = (res+sum)%MOD;
		}
		res = (res+(suffix[1]%MOD))%MOD;
		cout<<res<<endl;			
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
