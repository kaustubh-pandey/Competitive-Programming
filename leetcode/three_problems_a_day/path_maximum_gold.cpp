#include<bits/stdc++.h>
using namespace std;
//m rows and n columns
int dfs(vector<vector<int>>& grid,bool visited[][16],int i,int j,int m,int n){
int res = 0;
if(!visited[i][j] && grid[i][j]!=0){
    visited[i][j]=true;
    res+=grid[i][j];
    int maxm=0;
    if(i>0 && !visited[i-1][j] && grid[i-1][j]!=0){
        maxm=max(maxm,dfs(grid,visited,i-1,j,m,n));
    }
    if(i<m-1 && !visited[i+1][j] && grid[i+1][j]!=0){
        maxm=max(maxm,dfs(grid,visited,i+1,j,m,n));
    }
    if(j>0 && !visited[i][j-1] && grid[i][j-1]!=0){
        maxm=max(maxm,dfs(grid,visited,i,j-1,m,n));
    }
    if(j<n-1 && !visited[i][j+1] && grid[i][j+1]!=0){
        maxm=max(maxm,dfs(grid,visited,i,j+1,m,n));
    }
        res+=maxm;
        visited[i][j]=false;
    }
    return res;
}
int getMaximumGold(vector<vector<int>>& grid) {
	 if(grid.size()==0 || grid[0].size()==0){
	    return 0;
	 }
	 int m = grid.size();
	 int n = grid[0].size();
	 bool visited[16][16];
	 int ans=0;
	 for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        memset(visited,false,sizeof(visited));
	        ans = max(ans,dfs(grid,visited,i,j,m,n));
	    }
	 }
	 return ans;
}
int main(){
	vector< vector<int> > grid = {{1,0,7,0,0,0},{2,0,6,0,1,0},{3,5,6,7,4,2},{4,3,1,0,2,0},{3,0,5,0,20,0}};
	cout<<getMaximumGold(grid)<<endl;
	return 0;
}