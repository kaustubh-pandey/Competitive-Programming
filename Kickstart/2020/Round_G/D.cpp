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

void score(vector<ll> &a,ll scor,vector<ll> &scores,int n){
    if(n==1){
        scores.pb(scor);
        return;
    }
    //vector<ll> a_copy;
    int m = a.size();
    for(int i=0;i<m-1;i++){
        //a_copy = a;
        int k=0;
        if(a[i]==-1){continue;}
        if(a[i+1]==-1){
            while(i+k+1<m && a[i+k+1]==-1){
                k++;
            }
        }
        if(i+k+1>=m){continue;}
        if(a[i+k+1]==-1){continue;}
        ll val = a[i]+a[i+k+1];
        ll val1 = a[i];
        ll val2 = a[i+k+1];
        a[i]=val;
        a[i+k+1]=-1;
        //printvec(a);
        //cout<<scor<<endl;
        score(a,scor+val,scores,n-1);
        a[i]=val1;
        a[i+k+1]=val2;
        //cout<<"---"<<endl;
        //printvec(a);
    }
}
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        vector<ll> a(n,0);
        fo(i,n){
            cin>>a[i];
        }

        vector<ll> scores;
        score(a,0,scores,(int)a.size());
        ll sum = 0;
        for(auto x:scores){
            sum+=x;
        }
        cout<<fixed;
        cout<<setprecision(7);
        long double div = scores.size();
        long double asn = sum*1.0L/div;
        cout<<"Case #"<<z<<": "<<asn <<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/