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
#define TIK auto start = chrono::high_resolution_clock::now();
#define TOK auto end = chrono::high_resolution_clock::now();double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();time_taken *= 1e-9;cerr << "Time taken:" << fixed << time_taken << setprecision(9);cerr << " sec" << endl;
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//const int N=2e5;
//int arr[N+1];


int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    fo(i,n){
        cin>>a[i];
    }
    //precompute
    vector< vector< pair<int,int> > > dp((int)log2(n)+2,vector<pair<int,int>>(n+1,mp(0,0)));
    for(int j=0;j<n;j++){
        dp[0][j] = mp(a[j],0);
    }
    
    for(int i=1;(1<<i)<=n;i++){
        int len = 1<<(i-1);
        for(int j=0;j+len<n;j++){
            // cout<< "("<<dp[i-1][j].F<<","<<dp[i-1][j].S<<")"<<endl;
            // cout<< "("<<dp[i-1][j+len].F<<","<<dp[i-1][j+len].S<<")"<<endl;
            int sum = dp[i-1][j].F+dp[i-1][j+len].F;
            int count = dp[i-1][j].S+dp[i-1][j+len].S;
            if(sum>=10){
                count++;
            }
            // cout<<sum%10<<" "<<count<<endl;
            dp[i][j] = mp(sum%10,count);
        }
    }
    int t=1;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<dp[(int)log2(r-l+1)][l-1].S<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!
: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/