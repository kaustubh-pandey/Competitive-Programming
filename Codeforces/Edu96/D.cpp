#include<bits/stdc++.h>
#define ll long long
#define xll __int128
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
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
//const int N=2e5;
//int arr[N+1];

bool check(pair<int,int> seg){
	if(seg.S-seg.F>=1){
		return true;
	}
	return false;
} 
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int moves = 0;
		vector< pair<int,int> > q;
		int i=0;
		while(i<n){
			int j=i;
			while(j<n && s[i]==s[j]){
				j++;
			}
			q.pb(mp(i,j-1));
			i=j;
		}
		int start=0;
		int endi = q.size()-1;
		while(start<=endi){
			// cout<<q[start].F<<"  "<<q[start].S<<endl;
			if(check(q[start])){
				// cout<<"YES"<<endl;
				moves++;
				start++;
			}
			else{
				// cout<<"NO"<<endl;
				//find next block
				int flag=0;
				for(i=start;i<=endi;i++){
					if(check(q[i])){
						q[i] = mp(q[i].F,q[i].S-1);
						start++;
						moves++;
						flag=1;
						break;
					}	
				}
				if(!flag){
					// cout<<"LAST"<<endl;
					endi--;
					start++;
					moves++;
				}
			}
		}
		cout<<moves<<endl;
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
