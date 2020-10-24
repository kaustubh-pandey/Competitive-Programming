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

ll avg(int a[],int w){
    ll sum=0;
    fo(i,w){
        sum+=a[i];
    }
    ll res = sum*(1.0L)/w;
    return res;
}
ll minl(ll a,ll b){
    if(a<b){return a;}
    return b;
}
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int w,n;
        cin>>w>>n;
        int a[w];
        vector<ll> vals;
        fo(i,w){
            cin>>a[i];
            vals.pb(a[i]);
        }
        ll average = avg(a,w);
        vals.pb(average);vals.pb(average+1);
        ll minm = LLONG_MAX;
        for(int i=0;i<(int)vals.size();i++){
            ll loc_sum=0;
            for(int j=0;j<w;j++){
                ll value=0;
                if(vals[i]<a[j]){
                    //print(a[j]-vals[i],((vals[i]-a[j])%n)+n,i,j);
                    value = minl(a[j]-vals[i],((vals[i]-a[j])%n)+n);
                }
                else{
                    //print(vals[i]-a[j],((a[j]-vals[i])%n)+n,i,j);
                    value = minl(vals[i]-a[j],((a[j]-vals[i])%n)+n);
                }
                loc_sum+= value;
            }
            minm = minl(minm,loc_sum);
        }
        cout<<"Case #"<<z<<": "<< minm<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/