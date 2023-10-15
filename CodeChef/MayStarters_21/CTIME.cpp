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

struct INTERVAL{
    int s;
    int e;
};
bool cmp(INTERVAL a,INTERVAL b){
    if(a.s<b.s){
        return true;
    }
    else if(a.s==b.s){
        return a.e < b.e;
    }
    return false;
}
INTERVAL merge(INTERVAL a,INTERVAL b){
    INTERVAL res;
    res.s = min(a.s,b.s);
    res.e = max(a.e,b.e);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,k,f;
        cin>>n>>k>>f;
        vector<INTERVAL> slots;
        INTERVAL tmp;
        fo(i,n){
            cin>>tmp.s>>tmp.e;
            slots.pb(tmp);
        }
        sort(slots.begin(),slots.end(),cmp);
        vector<INTERVAL> merged;
        INTERVAL curr;
        int flag=1;
        for(INTERVAL x: slots){
            //cout<<x.s<<" "<<x.e<<endl;
            if(flag){
                curr=x;
                flag=0;
                continue;
            }
            if(curr.e<x.s || x.e<curr.s){
                //no intersect
                merged.pb(curr);
                curr=x;
            }
            else{
                curr = merge(curr,x);
            }

        }
        merged.pb(curr);
        ll maxm = 0;
        int skip=0;
        maxm += merged[0].s;
        if(maxm>=k){
            skip=1;
        }
        if(!skip){
            for(int i=0;i<(int)merged.size()-1;i++){
            maxm += merged[i+1].s-merged[i].e;
            if(maxm>=k){
                skip=1;
                break;
            }
            }
        }
        
        if(!skip){
            maxm += f-merged.back().e;
        }
        //cout<<maxm<<endl;
        if(maxm>=k){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!\n: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
