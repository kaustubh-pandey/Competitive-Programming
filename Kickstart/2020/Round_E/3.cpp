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

ll max(ll a,ll b){
	if(a>b){return a;}
	return b;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	fo(test_case,t){
		int n;
		cin>>n;
		vector< pair<int,int> > v;
		int e,r;
		fo(i,n){
			cin>>e>>r;
			v.pb(mp(e,r));	
		}
		if(n==1){
			cout<<"Case #"<<test_case+1<<": "<<0<<" "<<e <<endl;
		}
		else{
			vector<ll> ei(n,0);
			vector<ll> prefix(n,0);
			ll sum = 0;
			fo(i,n){
				sum+=v[i].F;
				prefix[i]=sum;	
			}
			fo(i,n){
				ei[i] = sum-v[i].F;	
			}	
			int crypoint=-1;
			fo(i,n){
				if(v[i].S>ei[i]){
					crypoint = i;
					break;
				}	
			}
			queue<int> q;
			q.push(crypoint);
			vector<int> visit(n,0);
			
			if(crypoint==-1){
					cout<<"Case #"<<test_case+1<<": 0 "<< "INDEFINITELY"<<endl;	
			}
			else{
				int flag=0;
				int count=0;
				ll maxm = sum+prefix[crypoint-1];
				while(!q.empty()){
					int pos = q.front();
					q.pop();
					count++;
					visit[pos]=1;
					ei.clear();
					prefix.clear();
					sum=0;
					fo(i,n){
						if(!visit[i]){
							sum+=v[i].F;
							prefix.pb(sum);	
						}
						else{prefix.pb(0);}	
					}
					fo(i,n){
						if(!visit[i]){
							ei.pb(sum-v[i].F);		
						}
						else{ei.pb(-100);}
					}	
					crypoint=-1;
					fo(i,n){
						if(!visit[i]){
							if(v[i].S>ei[i] && ei[i]!=-100){
							crypoint = i;
							break;
							}	
						}	
					}
					if(crypoint==-1){
						flag=1;
						break;	
					}
					else{
						maxm = max(sum+prefix[crypoint-1],maxm);
						q.push(crypoint);	
					}	
				}
				if(flag==1){
					cout<<"Case #"<<test_case+1<<": "<<count<<" "<< "INDEFINITELY"<<endl;		
				}
				else{
					cout<<"Case #"<<test_case+1<<": "<<count<<" "<<maxm <<endl;		
				}	
			}
		}
		
	}
	return 0;
}
