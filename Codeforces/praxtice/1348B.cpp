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
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		//trace(n);
		//trace(k);
		int a[n];
		set<int> st;
		fo(i,n){
			cin>>a[i];
			st.insert(a[i]);	
		}
		
		if((int)st.size()>k){
			cout<<-1<<endl;	
			continue;
		}
		else if((int)st.size()<k){
			for(int l=1;l<=n;l++){
				//cout<<l<<endl;
				st.insert(l);
				if((int)st.size()==k){break;}	
			}
			
		}
		cout<< n*k <<"\n";
		fo(i,n){
			for(auto it=st.begin();it!=st.end();it++){
				cout<< *it<<" ";	
			}
		}
		cout<<"\n";
	}
	return 0;
}
