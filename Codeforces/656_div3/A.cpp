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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x,y,z,a,b,c;
		cin>>x>>y>>z;
		if(x!=y){
			b=x;
			c=y;
			if(z==max(b,c)){
				cout<<"YES\n";
				cout<<min(b,c)<<" "<<b<<" "<<c<<endl;	
			}
			else{
				cout<<"NO\n";	
			}	
		}
		else if(x==y && y==z){
			cout<<"YES\n";
			cout<<x<<" "<<y<<" "<<z<<endl;	
		}
		else{
			//x==y &y!=z
			a=y;
			b=z;
			if(x==max(a,b)){
					cout<<"YES\n";
					cout<<min(a,b)<<" "<<a<<" "<<b<<endl;
			}
			else{
				cout<<"NO\n";	
			}	
		}			
	}
	return 0;
}
