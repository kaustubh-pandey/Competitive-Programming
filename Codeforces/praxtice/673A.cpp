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
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
//const int N=2e5;
//int arr[N+1];

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
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int t=0;
	int d[n];
	memset(d,0,sizeof(d));
	fo(i,n){
		cin>>d[i];	
	}
	int ans = 90;
	fo(i,n){
		//print(i,d[i]-t-1);
		if(d[i]-t-1>=15){
			ans = t+15;
			break;	
		}
		else{
			t=d[i];	
		}	
	}
	if(90-t-1>=15){
		ans = t+15;	
	}
	cout<<ans<<endl;
	return 0;
}
