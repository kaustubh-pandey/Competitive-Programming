#include<bits/stdc++.h>
#define ll long long
#define int long long
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
 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int> a;
		map<int,int> b;
		int tmp;
		fo(i,n){
			cin>>tmp;
			a[tmp]++;	
		}
		fo(i,n){
			cin>>tmp;
			b[tmp]++;	
		}
		map<int,int> excess_a;
		map<int,int> excess_b;
		int minm = INT_MAX;
		for(auto x:a){
			if(b[x.first]<x.second){
				excess_a[x.first]=x.second-b[x.first];	
			}
			minm = min(minm,x.first);	
		}
		
		for(auto x:b){
			if(a[x.first]<x.second){
				excess_b[x.first]=x.second-a[x.first];	
			}
			minm = min(minm,x.first);		
		}
		
			if(excess_a.size()==0 && excess_b.size()==0){
				cout<<0<<endl;	
			}
			else{
				bool flag1=true,flag2=true;
				for(auto y:excess_a){
					//print(y.first,y.second);
					if(y.second%2){flag1=false;break;}	
				}
				for(auto y:excess_b){
					//print(y.first,y.second);
					if(y.second%2){flag2=false;break;}	
				}
				//print(flag1,flag2,excess_a.size(),excess_b.size());	
				if(flag1 && flag2){
					vector<int> al;
					vector<int> bl;
					for(auto y:excess_a){
						for(int k=0;k<y.second/2;k++){
							al.pb(y.first);	
						}	
					}
					for(auto y:excess_b){
						for(int k=0;k<y.second/2;k++){
							bl.pb(y.first);	
						}	
					}
					ll sum=0;
					sort(al.begin(),al.end());
					sort(bl.rbegin(),bl.rend());
					for(int i=0;i<(int)al.size();i++){
						sum+= min(2*minm,min(al[i],bl[i]));	
					}
					cout<<sum<<endl;
				}
				else{
					cout<<-1<<endl;	
				}	
			}	
	
		
	}
	return 0;
}
