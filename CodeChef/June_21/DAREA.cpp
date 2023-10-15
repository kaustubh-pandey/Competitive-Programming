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

ll calc(map<int,pair<int,int> > xToy){
    vector<ll> prefix;
    ll area = 0;
    int length = 0;
    int breadth = 0;
    pair<int,int> edge = {xToy.begin()->S.F,xToy.begin()->S.S};
    length = xToy.begin()->S.S - xToy.begin()->S.F;
    prefix.pb(0);
    auto itr = xToy.begin();
    //print(itr->first,itr->second.F,itr->second.S);
    int prevX = itr->F;
    auto endItr = --xToy.end();
    itr++;
    while(itr!=endItr){
        //expand rectangle
        //print(itr->first,itr->second.F,itr->second.S);
        edge.F = min(edge.F,itr->S.F);
        edge.S = max(edge.S,itr->S.S);
        length = edge.S - edge.F;
        breadth = itr->F - prevX;
        area = 1LL*length * breadth;
        prefix.pb(area);
        itr++;
    }
    //cout<<endl;
    //printvec(prefix);
    //return 0;
    //repeat same from right side
    vector<ll> suffix;
    area = 0,length = 0,breadth=0;
    edge = {xToy.rbegin()->S.F,xToy.rbegin()->S.S};
    suffix.pb(0);
    auto revItr = xToy.rbegin();
    prevX = revItr->F;
    auto endRevItr = --xToy.rend();
    revItr++;
    //cout<<0<<" ";
    while(revItr!=endRevItr){
        edge.F = min(edge.F,revItr->S.F);
        edge.S = max(edge.S,revItr->S.S);
        length = edge.S - edge.F;
        breadth = prevX - revItr->F;
        area = 1LL*length*breadth;
        //cout<<area<<" ";
        suffix.pb(area);
        revItr++;
    }
    //cout<<endl;
    //find min of sum of areas
    ll min_area = LLONG_MAX;
    int n = prefix.size();
    fo(i,n){
        min_area = min(min_area,prefix[i]+suffix[n-i-1]);
    }
    return min_area;
}
ll min(ll a,ll b){
    if(a<b){
        return a;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,pair<int,int> > xToy;
        map<int,pair<int,int> > yTox;  
        int x,y;    
        fo(i,n){
            cin>>x>>y;
            if(xToy.find(x)!=xToy.end()){
                xToy[x].F = min(xToy[x].F,y);
                xToy[x].S = max(xToy[x].S,y);
            }
            else{
                xToy[x].F =y;
                xToy[x].S =y;
            }
            if(yTox.find(y)!=yTox.end()){
                yTox[y].F = min(yTox[y].F,x);
                yTox[y].S = max(yTox[y].S,x);
            }
            else{
                yTox[y].F =x;
                yTox[y].S =x;
            }
        }
        ll minX = (xToy.size()==1)?0:calc(xToy);
        ll minY = (yTox.size()==1)?0:calc(yTox);
        //print(minX,minY);
        cout<< min(minX,minY) <<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!\n: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
