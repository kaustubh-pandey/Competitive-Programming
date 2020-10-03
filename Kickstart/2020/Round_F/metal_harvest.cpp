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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        vector< pair<int,int> > v;
        int s,e;
        fo(i,n){
            cin>>s>>e;
            v.pb(mp(s,e));
        }
        sort(v.begin(),v.end());
        int start = v[0].F;
        int count=0;
        int i=0;
        while(i<n){
            int endi = start+k;
            while(i<n && endi>=v[i].S){
                i++;
            }
            count++;
            if(i==n){break;}
            start = max(v[i].F,endi);
        }
        cout<<"Case #"<<z+1<<": "<<count<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/