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

int score(string s){
    int sum=0;
    for(int i=0;i<(int)s.size();i++){
        if(i>0 && s[i]=='W' && s[i-1]=='W'){
            sum+=2;
        }
        else if(s[i]=='W'){
            sum+=1;
        }
    }
    return sum;
}
int bf(string s,int n,int k,map<pair<string,int>,int> &dp){
    if(k==0){
        return dp[mp(s,k)]=score(s)+1;
    }
    if(dp[mp(s,k)]!=0){
        return dp[mp(s,k)];
    }
    int maxm = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            s[i]='W';
            maxm = max(maxm,bf(s,n,k-1,dp));
            s[i]='L';
        }
    }
    return dp[mp(s,k)]=maxm;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int countl = 0;
        int countw=0;
        fo(i,n){
            if(s[i]=='L'){countl++;}
            else{countw++;}
        }
        k = min(k,countl);
        int i=0;
        vector<int> segs;
        while(i<n){
            int j=i;
            while(j<n && s[j]=='L'){
                j++;
            }
            segs.pb(j-i);
            i=j+1;
        }
        sort(segs.begin(),segs.end());
        int i=0;
        while(k>0 && i<(int)segs.size()){
            if(segs[i]<k){
                k-=segs[i];
                i++;
                countw+= 
            }
        }
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/