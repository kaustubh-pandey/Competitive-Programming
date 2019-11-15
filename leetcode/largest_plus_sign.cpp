#include<bits/stdc++.h>
using namespace std;
/*
In the original grid 0 and 1 are exchanged as initializing with 1 using
memset isn't possible. memset supports either 0 or -1 initialization
*/
/*
General idea :
Build 4 matrices, left to right, top to bottom and vice versas
l2r contains number of 0's from left to right till (i,j) but only contiguous
Example : 011100110 will have l2r as 100012001
Build all 4 matrices from each direction in similar way
Then for each (i,j) if center has 0 then order is min of all the directions w.r.t that center +1(for center)
*/
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    int grid[N][N];
    memset(grid,0,sizeof(grid));
    for(auto x:mines){
        grid[x[0]][x[1]]=1;
    }
    int l2r[N][N],t2d[N][N];
    int r2l[N][N],d2t[N][N];
    memset(l2r,0,sizeof(l2r));
    memset(r2l,0,sizeof(r2l));
    memset(t2d,0,sizeof(t2d));
    memset(d2t,0,sizeof(d2t));
    //prefix array left to right
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j==0 && grid[i][j]==0){
                l2r[i][j]=1;
            }
            else if(grid[i][j]==0){
                l2r[i][j]=l2r[i][j-1]+1;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=0;j--){
            if(j==N-1 && grid[i][j]==0){
                r2l[i][j]=1;
            }
            else if(grid[i][j]==0){
                r2l[i][j]=r2l[i][j+1]+1;
            }
        }
    }
    //prefix array top to down
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if(i==0 && grid[i][j]==0){
                t2d[i][j]=1;
            }
            else if(grid[i][j]==0){
                t2d[i][j]=t2d[i-1][j]+1;
            }
        }
    }
    for(int j=0;j<N;j++){
        for(int i=N-1;i>=0;i--){
            if(i==N-1 && grid[i][j]==0){
                d2t[i][j]=1;
            }
            else if(grid[i][j]==0){
                d2t[i][j]=d2t[i+1][j]+1;
            }
        }
    }
    //find ll,lr,lt,ld, take min for each center
    int maxm=0,val;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            val=0;
            if(grid[i][j]==0){
                if(i==0 || j==0 || i==N-1 || j==N-1){
                    val=1;
                }
                else{
                    int ll = l2r[i][j-1];
                    int lr = r2l[i][j+1];
                    int lt = t2d[i-1][j];
                    int ld = d2t[i+1][j];
                    val=min(min(ll,lr),min(lt,ld))+1;
                } 
                maxm=max(maxm,val);
            }
        }
    }
    return maxm;  
}

int main(){
	
	return 0;
}