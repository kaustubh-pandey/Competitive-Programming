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
//partX.F < partY.F
int crashTime(pair<int,char> partX,pair<int,char> partY,int m){
    int a = partX.F;
    int b = partY.F;
    char adir = partX.S;
    char bdir = partY.S;
    if(adir=='L'){
        if(bdir=='L'){
            return (a+b)/2;
        }
        else{
            return (2*m-b+a)/2;
        }
    }
    else{
        if(bdir=='L'){
            return (b-a)/2;
        }
        else{
            return (2*m-a-b)/2;
        }
    }
}
void process(vector< pair<int,char> > particles,int m,unordered_map<int,int> &timings){
    stack< pair<int,char> > st;
    for(auto x:particles){
        if(st.empty()){
            //cout<<x.F<<endl;
            //if no particles on left of current particle, it can be considered right moving(after refelection)
            st.push(x);
        }
        else{
            if(x.S=='L'){
                pair<int,char> part = st.top();
                st.pop();
                int time = crashTime(part,x,m);
                timings[part.F] = time;
                timings[x.F] = time;
            }
            else{
                //cout<<x.F<<endl;
                st.push(x);
            }
        }
    }
    //only right going particles left
    //pop in pairs and update time
    //cout<<"#"<<st.size()<<endl;
    while(!st.empty()){
        pair<int,char> part1 = st.top();
        st.pop();
        if(st.empty()){
            timings[part1.F] = -1; //the only particle left
            break;
        }
        pair<int,char> part2 = st.top();
        st.pop();
        int time = crashTime(part2,part1,m);
        timings[part1.F] = time;
        timings[part2.F] = time;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        fo(i,n){
            cin>>a[i];
        }
        vector< pair<int,char> > evenParticles;
        vector< pair<int,char> > oddParticles;
        char c;
        fo(i,n){
            cin>>c;
            if(a[i]%2){
                oddParticles.pb(mp(a[i],c));
            }
            else{
                evenParticles.pb(mp(a[i],c));
            }
        }       
        sort(oddParticles.begin(),oddParticles.end());
        sort(evenParticles.begin(),evenParticles.end());
        unordered_map<int,int> timings;
        process(oddParticles,m,timings);
        process(evenParticles,m,timings);
        fo(i,n){
            cout<< timings[a[i]] <<" ";
        }
        cout<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!\n: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
