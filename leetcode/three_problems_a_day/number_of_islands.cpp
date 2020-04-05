class Solution {
public:
    void dfs(vector<vector<char>>& grid,int srci,int srcj,int m,int n,bool visited[][1000]){
        if(!visited[srci][srcj] && grid[srci][srcj]=='1'){
            visited[srci][srcj]=true;
            if(srci-1>=0 && !visited[srci-1][srcj] && grid[srci-1][srcj]=='1'){
                dfs(grid,srci-1,srcj,m,n,visited);
            }
            if(srcj-1>=0 && !visited[srci][srcj-1] && grid[srci][srcj-1]=='1'){
                dfs(grid,srci,srcj-1,m,n,visited);
            }
            if(srci+1<m && !visited[srci+1][srcj] && grid[srci+1][srcj]=='1'){
                dfs(grid,srci+1,srcj,m,n,visited);
            }
            if(srcj+1<n && !visited[srci][srcj+1] && grid[srci][srcj+1]=='1'){
                dfs(grid,srci,srcj+1,m,n,visited);
            }
        }
    }
    int DFS(vector<vector<char>>& grid,int m,int n){
        bool visited[1000][1000];
        memset(visited,false,sizeof(visited));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,i,j,m,n,visited);
                    count++;
                }
            }
        }
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0){
            return 0;
        }
        int n= grid[0].size();
        return DFS(grid,m,n);
    }
};