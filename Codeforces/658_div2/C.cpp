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
void flip(string &st, int s,int e){
	for(int i=s;i<=e;i++){
		if(st[i]=='1'){
			st[i]='0';	
		}
		else{
			st[i]='1';	
		}	
	}	
}
void reve(string &st, int s,int e){
	reverse(st.begin()+s,st.begin()+e+1);	
} 
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a;
		string b;
		cin>>a;
		cin>>b;
		//int flag=0;
		if(a==b){
			cout<<0<<endl;
			continue;	
		}
		vector<int> res;
		fo(i,n){
			if(a[i]!=b[i]){
				flip(a,0,i);
				reve(a,0,i);
				res.pb(i+1);
				flip(a,0,0);
				res.pb(1);
				flip(a,0,i);
				reve(a,0,i);
				res.pb(i+1);
			}	
		}
		//cout<<a<<endl;
		cout<<res.size()<<" ";
		for(int x:res){
			cout<<x<<" ";	
		}
		cout<<endl;
	}
	return 0;
}
