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
void bfs(int x,int n,vector<int> &res){
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top<=x){
			res.pb(top);
			int last_dig = top%10;
			if(last_dig==0){
				q.push(top*10+last_dig+1);	
			}
			else if(last_dig==9){
				q.push(top*10+last_dig-1);	
			}
			else{
				q.push(top*10+last_dig+1);
				q.push(top*10+last_dig-1);
			}	
		}
	}	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> res;
		res.pb(0);
		for(int i=1;i<=9 && i<=n;i++){
			bfs(n,i,res);	
		}
		sort(res.begin(),res.end());
		for(auto x:res){
			cout<<x<<" ";	
		}
		cout<<endl;			
	}
	return 0;
}
