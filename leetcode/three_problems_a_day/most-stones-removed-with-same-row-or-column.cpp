#include<bits/stdc++.h>
using namespace std;
//connected components; Use disjoint sets for better runtime complexity
//DFS based approach
class Solution {
public:
    int dfs(vector<int> g[],int src,bool visited[]){
        int count=0;
        if(visited[src]==false){
            visited[src]=true;
            count++;
            for(auto i = g[src].begin();i!=g[src].end();i++){
                count+=dfs(g,*i,visited);
            }
        }
        return count;
    }
    int DFS(vector<int> g[],int n){
        bool visited[n];
        memset(visited,false,sizeof(visited));
        int res=0;
        for(int i=0;i<n;i++){
            int tmp=dfs(g,i,visited);
            res+= (tmp>0)?tmp-1:0;
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> g[stones.size()];
        for(int i=0;i<stones.size()-1;i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        return DFS(g,stones.size());
        
    }
};