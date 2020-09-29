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

 
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	fo(test_case,t){
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		int left = a-c;
		int right = b-c;
		int not_vib = n-(a+b-c);
		if(not_vib>=0 && n==1){
			if(a!=1 || b!=1 || c!=1){
				cout<<"Case #"<<test_case+1<<": "<<"IMPOSSIBLE"<<endl;
			}
			else{
				cout<<"Case #"<<test_case+1<<": "<< 1<<endl;	
			}	
		}
		else if(not_vib>=0 && n==2){
			if(not_vib>0){
				cout<<"Case #"<<test_case+1<<": "<<"IMPOSSIBLE"<<endl;
			}
			else if(a>b){
				cout<<"Case #"<<test_case+1<<": "<< 1 <<" "<<2<<endl;
			}
			else if(a<b){
				cout<<"Case #"<<test_case+1<<": "<< 2 <<" "<<1<<endl;	
			}
			else{
				cout<<"Case #"<<test_case+1<<": "<< 2 <<" "<<2<<endl;	
			}
		}
		else if(not_vib>=0 && left+right+c>=2){
			deque<int> dq;
			fo(i,not_vib){
				dq.pb(1);	
			}
			if(c==1){
				if(b<a){
					dq.push_back(n);		
				}
				else{
					dq.push_front(n);
				}	
			}
			else if(c>=2){
				dq.push_front(n);
				fo(i,c-1){
					dq.push_back(n);
				}	
			}
			fo(i,left){
				dq.push_front(n-1);	
			}
			fo(i,right){
				dq.push_back(n-1);	
			}
			
			cout<<"Case #"<<test_case+1<<": ";
			while(!dq.empty()){
				cout<<dq.front()<<" ";
				dq.pop_front();	
			}
			cout<<endl;
		}
		else{
			cout<<"Case #"<<test_case+1<<": "<<"IMPOSSIBLE"<<endl;
		}	
	}
	return 0;
}
