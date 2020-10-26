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
ll absl(ll a){
    if(a>0){return a;}
    return -a;
}
ll minl(ll a,ll b){
    if(a<b){return a;}
    return b;
}
int bsearch(int a[],int low,int high,int n,int x,int l,int r){
    if(high>=low){
        int mid = low+(high-low)/2;
        // cout<<x<<" "<<a[mid]<<"  "<<mid<<endl;
        
        if(x-a[mid]==n-x+a[mid]){
            return mid;
        }
        if(mid+1<=r && (x-a[mid]>=n-x+a[mid] && x-a[mid+1]<n-x+a[mid+1])){
            return mid;
        }
        if(mid-1>=l && (x-a[mid-1]>=n-x+a[mid-1] && x-a[mid]<n-x+a[mid])){
            return mid-1;
        }
        if(x-a[mid]<n-x+a[mid]){
            return bsearch(a,low,mid-1,n,x,l,r);
        }
        else{
            return bsearch(a,mid+1,high,n,x,l,r);
        }
    }
    // cout<<high<<" "<<low<<"#"<<endl;
    if(high<l){
        return high;
    }
    if(low>r){
        return low;
    }
    return high;
}
int bsearch2(int a[],int low,int high,int n,int x,int l,int r){
    if(high>=low){
        int mid = low+(high-low)/2;
        if(a[mid]-x==n+x-a[mid]){
            return mid;
        }
        if(mid+1<=high && (a[mid]-x<=n+x-a[mid] && a[mid+1]-x>n+x-a[mid+1])){
            return mid;
        }
        if(mid-1>=l && (a[mid-1]-x<=n+x-a[mid-1] && a[mid]-x>n+x-a[mid])){
            return mid-1;
        }
        if(a[mid]-x<n+x-a[mid]){
            return bsearch2(a,mid+1,high,n,x,l,r);
        }
        else{
            return bsearch2(a,low,mid-1,n,x,l,r);
        }
    }
    // cout<<high<<" "<<low<<"#"<<endl;
    if(high<l){
        return high;
    }
    if(low>r){
        return low;
    }
    return low;
}
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int w,n;
        cin>>w>>n;
        int a[w];
        fo(i,w){
            cin>>a[i];
        }
        sort(a,a+w);
        ll prefix[w];
        prefix[0]=a[0];
        Fo(i,1,w){
            prefix[i] = prefix[i-1]+a[i];
        }
        ll minm = LLONG_MAX;
        for(int i=0;i<w;i++){
            int pos = bsearch(a,0,i,n,a[i],0,i);
            // cout<<"---------"<<endl;
            int pos2 = bsearch2(a,i+1,w-1,n,a[i],i+1,w-1);
            // cout<<"---------"<<endl;
            // cout<<pos<<" "<<pos2<<endl;
            ll val=0;
            //pos+1 to i
            if(pos<=i){
                if(pos<0){
                    val+=1LL*(i+1)*a[i] - (prefix[i]);
                }
                else{
                    val+=1LL*(i-pos)*a[i] - (prefix[i]-prefix[pos]);
                }
                
            }
            // cout<<val<<endl;
            // 0 to pos
            if(pos>=0){
                if(pos>i){
                    val+= 1LL*(i+1)*(n-a[i]) + prefix[i];
                }
                else{   
                    val+= 1LL*(pos+1)*(n-a[i]) + prefix[pos];
                }
            }
            // cout<<val<<endl;
            //pos2+1 to w-1
            if(pos2<=w-1){
                if(pos2<i+1){
                    val+= 1LL*(w-i-1)*(n+a[i]) -(prefix[w-1]-prefix[i]);
                }
                else{
                    val+= 1LL*(w-pos2-1)*(n+a[i]) -(prefix[w-1]-prefix[pos2]);
                }
            }
            // cout<<val<<endl;
            //i+1 to pos2
            if(pos2>=i+1){
                if(pos2>w-1){
                    val+= (prefix[w-1]-prefix[i])-1LL*(w-i-1)*a[i];
                }
                else{
                    val+= (prefix[pos2]-prefix[i])-1LL*(pos2-i)*a[i];
                }
            }
            // cout<<val<<endl;
            minm = minl(minm,val);
        }
        cout<<"Case #"<<z<<": "<< minm<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/