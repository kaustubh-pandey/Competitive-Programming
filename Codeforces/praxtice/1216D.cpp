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


ll min(ll a,ll b){
	if(a<b){return a;}
	return b;	
}

ll max(ll a,ll b){
	if(a>b){return a;}
	return b;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		fo(i,n){cin>>a[i];}
		ll sum=0;
		ll maxm = 0;
		fo(i,n){
			sum+=a[i];
			maxm = max(a[i],maxm);	
		}
		ll avg = sum/n +1;
		ll c = max(maxm,avg);
		//cout<<c<<endl;
		ll b[n];
		fo(i,n){
			b[i]=c-a[i];	
		}
		ll GCD = b[0];
		Fo(i,1,n){
			if(b[i]!=0){
				GCD = __gcd(GCD,b[i]);	
			}	
		}
		//cout<<GCD<<endl;
		ll sum2=0;
		fo(i,n){
			sum2+= b[i]/GCD;	
		}
		cout<< sum2<<" "<<GCD <<endl;		
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
