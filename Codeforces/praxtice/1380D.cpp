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
ll max(ll a ,ll b){
	if(a>b){return a;}
	return b;	
}
ll cost(vector<int> seg, pair<int,int> bounds,ll k,ll f,ll b){
	ll maxp = -1;
	for(auto x:seg){
		maxp = max(maxp,x);	
	}
	ll n= seg.size();
	ll l = bounds.F;
	ll r = bounds.S;
	if(n>=k){
		if(b*k< f){
			if(maxp>l && maxp>r){
				return (n-k)*b+f;
			}
			return n*b;	
		}
		return (n%k)*b + (n/k)*f;
	}
	if(maxp>l && maxp>r){
		return -1;
	}
	return n*b;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int x,y,k;
	cin>>n>>m;
	cin>>x>>k>>y;
	int a[n];
	int b[m];
	unordered_map<int,int> check;
	fo(i,n){
		cin>>a[i];
		check[a[i]]++;	
	}
	fo(i,m){
		cin>>b[i];	
	}
	if(n>m){
		int flag=0;
		fo(i,m){
			if(check[b[i]]==0){flag=1;break;}
		}
		if(flag){
			cout<<-1<<endl;	
		}
		else{
			vector< pair< vector<int> , pair<int,int> > > v;
			vector<int> tmp;
			int i=0;
			int j=1;
			if(a[0]!=b[0]){
				while(i<n && a[i]!=b[0]){
					tmp.pb(a[i]);
					i++;	
				}
				v.pb(mp(tmp,mp(-1,b[0])));
				tmp.clear();	
			}
			int l,r;
			while(i<n && j<m){
				l= a[i];i++;
				while(i<n && a[i]!=b[j]){
					tmp.pb(a[i]);
					i++;	
				}
				r=b[j];j++;
				v.pb(mp(tmp,mp(l,r)));
				tmp.clear();	
			}
			l=a[i];i++;
			while(i<n){
				tmp.pb(a[i]);
				i++;	
			}
			if(tmp.size()){
				v.pb(mp(tmp,mp(l,-1)));
				tmp.clear();	
			}
			ll sum=0;
			ll cust=-1;
			for(auto w:v){
				//for(auto q:w.F){
					//cout<<q<<" ";	
				//}
				//cout<<endl;
				//trace(w.S.F);
				//trace(w.S.S);
				cust = cost(w.F,w.S,k,x,y);
				if(cust==-1){
					break;	
				}
				sum+=cust;	
			}
			if(cust==-1){cout<<-1<<endl;}
			else{
				cout<<sum<<endl;	
			}
		}	
	}
	else if(n==m){
		int flag=0;
		fo(i,n){
			if(a[i]!=b[i]){flag=1;break;}	
		}
		if(flag){
			cout<<-1<<endl;	
		}
		else{
			cout<<0<<endl;	
		}
	}
	else{
		cout<<-1<<endl;	
	}
	return 0;
}
