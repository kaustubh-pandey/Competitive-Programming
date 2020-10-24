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
//const int N=2e5;
//int arr[N+1];


int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        string s;
        cin>>s;
        int n=s.size();
        vector<int> kicks;
        vector<int> starts;
        fo(i,n){
            if(s[i]!='K'){
                continue;
            }
            if(s[i]=='K' && i<n-3){
                if(s[i+1]=='I' && s[i+2]=='C' && s[i+3]=='K'){
                    kicks.pb(i+3);
                    i+=2;
                }
            }
        }
        fo(i,n){
            if(s[i]!='S'){
                continue;
            }
            if(s[i]=='S' && i<n-4){
                if(s[i+1]=='T' && s[i+2]=='A' && s[i+3]=='R' && s[i+4]=='T'){
                    starts.pb(i);
                    i+=4;
                }
            }
        }
        int res=0;
        for(auto x:kicks){
            auto itr = upper_bound(starts.begin(),starts.end(),x);
            res+= starts.end()-itr;
        }
        cout<<"Case #"<<z<<": "<< res<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/