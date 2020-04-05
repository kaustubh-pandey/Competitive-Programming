class Solution {
public:
    void dfs(vector< pair<int,int> > g[],int src,int time,int visited[]){
        if(visited[src]==-1 || visited[src]>time){
            visited[src]=time;
            for(auto node: g[src]){
                dfs(g,node.first,visited[src]+node.second,visited);  
            }   
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector< pair<int,int> > g[N+1];
        for(auto x:times){
            g[x[0]].push_back(make_pair(x[1],x[2]));  
        }
        int visited[N+1];
        for(int i=0;i<=N;i++){
            visited[i]=-1;
        }
        dfs(g,K,0,visited);
        int maxm=-1;
        for(int i=1;i<=N;i++){
            if(visited[i]==-1){
                return -1;
            }
            maxm = max(maxm,visited[i]);
        }
        return maxm;
    }
};