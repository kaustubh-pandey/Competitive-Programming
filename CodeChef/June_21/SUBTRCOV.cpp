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
void printSet(set<int> s){
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<endl;
}
pair<int,int> bfs(int src,vector<int>G[],int n){
    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int x:G[tmp]){
            //not visited
            if(dist[x]==-1){
                dist[x] = dist[tmp]+1;
                q.push(x);
            }
        }
    }

    //go through all nodes and find one with max distance
    int max_dist = 0;
    int node = -1;
    Fo(i,1,n+1){
        if(dist[i]>max_dist){
            max_dist = dist[i];
            node = i;
        }
    }
    dist.clear();
    return {max_dist,node};
}
void dfs(int src,int dest,vector<int> G[],vector<int> &visited,stack<int> &st,vector<bool> &isLeaf,vector<int> &pathNodes){
    if(src==dest){
        st.push(src);
        visited[src]=1;
        if(G[src].size()==1){
            isLeaf[src]=true;
        }
        //enter all values in vector
        while(!st.empty()){
            pathNodes.pb(st.top());
            st.pop();
        }
        for(int i=(int)pathNodes.size()-1;i>=0;i--){
            st.push(pathNodes[i]);
        }
        st.pop();
        return;
    }
    if(!visited[src]){
        visited[src]=1;
        st.push(src);
        if(G[src].size()==1){
            //no children so leaf node
            isLeaf[src]=true;
        }
        for(int x:G[src]){
            if(!visited[x]){
                dfs(x,dest,G,visited,st,isLeaf,pathNodes);
            }
        }
        st.pop();
    }
}
void dfs2(int src,int dis,vector<int> G[],vector<int> &visited,vector<int> &dist){
    if(!visited[src]){
        visited[src]=1;
        //update current node distance if not updated
        if(dist[src]==-1){
            dist[src] = dis+1;
        }
        for(int x:G[src]){
            if(!visited[x]){
                dfs2(x,dist[src],G,visited,dist);
            }
        }
    }
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.F>b.F){
        return true;
    }
    else if(a.F==b.F){
        if(a.S>b.S){
            return true;
        }
        return false;
    }
    return false;
}
vector< pair<int,int> > DFS(int src,int dest,vector<int> G[],int n){
    vector<int> visited(n+1,0);
    stack<int> st;
    vector<bool> isLeaf(n+1,false);
    vector<int> pathNodes;
    //dfs to find path nodes
    dfs(src,dest,G,visited,st,isLeaf,pathNodes);
    visited.clear();
    visited = vector<int>(n+1,0);
    //do another dfs to update distance of leaf nodes from path
    vector<int> dist(n+1,-1);
    for(int x:pathNodes){
        dist[x]=0;
    }
    dfs2(src,0,G,visited,dist);
    printvec(dist);
    //return dist of all leaf nodes in decreasing order
    vector< pair<int,int> > res;
    for(int i=1;i<=n;i++){
        if(isLeaf[i]){
            res.pb(mp(dist[i],i));
        }
    }
    sort(res.begin(),res.end(),cmp);
    return res;
}
set<int> solve(int src,vector<int> G[],int n,int k){
    //2 times bfs to get the diameter end nodes
    pair<int,int> start_node = bfs(src,G,n);
    pair<int,int> end_node = bfs(start_node.S,G,n);
    int max_dist = end_node.F+1;
    int d1 = start_node.S;
    int d2 = end_node.S;
    set<int> nodes;
    nodes.insert(d1);
    nodes.insert(d2);
    if(max_dist>=k){
        //already enough
        return nodes;
    }
    //print(k,"#");
    //printSet(nodes);
    k -= max_dist;
    //print(k,"#");
    vector< pair<int,int> > rem = DFS(d1,d2,G,n);
    for(auto x:rem){
        if(nodes.find(x.S)==nodes.end()){
            nodes.insert(x.S);
            k-= x.F;
        }
        if(k<=0){
            break;
        }
    }
    return nodes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int u,v;
        vector<int> G[n+1];
        int src = -1;
        fo(i,n-1){
            cin>>u>>v;
            src = min(u,v);
            G[u].pb(v);
            G[v].pb(u);
        }
        if(k==1 || n==1){
            cout<<1<<endl;
            continue;
        }
        set<int> nodes = solve(src,G,n,k);
        printSet(nodes);
        cout<<nodes.size()<<endl;
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!\n: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
