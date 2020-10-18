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
		int operation=0;
		fo(i,n){
			if(s[i]=='2'){
				continue;
			}
			//cout<<s<<endl;
			if(i<n-2){
				if(s[i]==s[i+1] && s[i+1]==s[i+2]){
					int j=i;
					char val = s[i];
					while(j<n && val==s[j]){
						s[j]='2';
						j++;
					}
					operation++;
					i = j-1;
				}
				else{
					s[i]='2';
					s[i+1]='2';
					operation++;
					i++;
				}
			}
			else{
				if(i==n-2){
					s[i]='2';
					s[i+1]='2';
				}
				else if(i==n-1){
					s[i]='2';
				}
				operation++;
				break;
			}
		}
		//cout<<s<<endl;
		fo(i,n){
			if(s[i]!='2'){
				operation++;
			}
		}
		cout<<operation<<endl;			
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
