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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,w,m;
	cin>>h>>w>>m;
	vector<int> rows(h,0);
	vector<int> cols(w,0);
	int x,y;
	map< pair<int,int> ,int>dict;
	fo(i,m){
		cin>>x>>y;
		x--;y--;
		rows[x]+=1;
		cols[y]+=1;
		dict[mp(x,y)]=1;	
	}
	vector< pair<int,int> > rc;
	fo(i,h){
		rc.pb(mp(rows[i],i));	
	}
	vector< pair<int,int> > cc;
	fo(i,w){
		cc.pb(mp(cols[i],i));
	}
	sort(rc.rbegin(),rc.rend());
	sort(cc.rbegin(),cc.rend());
	vector< pair<int,int> > rcp;
	vector< pair<int,int> > ccp;
	int rmax = rc[0].F;
	int cmax = cc[0].F;
	int k=0;
	while(k<(int)rc.size() && rc[k].F==rmax){
		rcp.pb(rc[k]);
		k++;	
	}
	k=0;
	while(k<(int)cc.size() && cc[k].F==cmax){
		ccp.pb(cc[k]);
		k++;	
	}
	int flag=1;
	fo(i,(int)rcp.size()){
		fo(j,(int)ccp.size()){
			if(dict[mp(rcp[i].S,ccp[j].S)]==0){
				flag=0;
				break;	
			}
		}	
	}
	cout<<rmax+cmax-flag<<endl;
	return 0;
}
