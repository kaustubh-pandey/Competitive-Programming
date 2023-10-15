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
bool allvisited(int visited[],int n){
    for(int i=1;i<n;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
void dfs(int mat[][9],int src,int n,int visited[],int k,int &count){
    if(!visited[src]){
        visited[src]=1;
        if(allvisited(visited,n)){
            if(k==mat[src][0]){
                count++;
            }
            //return;
        }
        for(int i=1;i<n;i++){
            if(!visited[i]){
                dfs(mat,i,n,visited,k-mat[src][i],count);
            }
        }
        visited[src]=0;
    }
}
int DFS(int mat[][9],int n,int k){
    int visited[n];
    int count=0;
    for(int i=1;i<n;i++){
        //choice of second city
        memset(visited,0,sizeof(visited[0])*n);
        int k_copy = k;
        k_copy -= mat[0][i];
        dfs(mat,i,n,visited,k_copy,count);
    }
    return count;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      int mat[9][9];
      fo(i,n){
          fo(j,n){
              cin>>mat[i][j];
          }
      }
      cout<<DFS(mat,n,k)<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!
: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/