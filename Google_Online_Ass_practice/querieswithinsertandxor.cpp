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
 
int main(){
	vector<int> s = {0};
	int n;
	cin>>n;
	vector<int> index;
	vector<int> v;
	while(n--){
		int t,val;
		cin>>t>>val;
		if(t==0){s.pb(val);}
		else{
			index.pb(s.size());
			v.pb(val);	
		}	
	}
	int xoor = v[0];
	Fo(i,1,(int)v.size()){
		xoor = xoor^v[i];	
	}
	//print(xoor);
	int start=0;
	for(int i=0;i<(int)index.size();i++){
		for(int k=start;k<index[i];k++){
			s[k] = s[k]^xoor;	
		}
		xoor = xoor^v[i];
		start=index[i];	
	}
	//sort(s.begin(),s.end());
	for(auto x:s){
		cout<<x<<" ";	
	}
	cout<<endl;
	return 0;
}
