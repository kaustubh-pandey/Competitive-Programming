class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =  grid.size();
        if(n==0){
            return -1;
        }
        int m=grid[0].size();
        queue< pair<int,int> >q;
        int count_1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    count_1++;
                }
            }
        }
        queue< pair<int,int> >tmp;
        int count=0;
        if(q.empty()){
            if(count_1!=0){
                return -1;
            }
            return 0;
        }
        while(!q.empty()){
            pair<int,int> curr = q.front();
           
                if(curr.first-1>=0 && grid[curr.first-1][curr.second]==1){
                    grid[curr.first-1][curr.second]=2;
                    tmp.push(make_pair(curr.first-1,curr.second));
                }
                if(curr.first+1<n && grid[curr.first+1][curr.second]==1){
                    grid[curr.first+1][curr.second]=2;
                    tmp.push(make_pair(curr.first+1,curr.second));
                }
                if(curr.second-1>=0 && grid[curr.first][curr.second-1]==1){
                    grid[curr.first][curr.second-1]=2;
                    tmp.push(make_pair(curr.first,curr.second-1));
                }
                if(curr.second+1<m && grid[curr.first][curr.second+1]==1){
                    grid[curr.first][curr.second+1]=2;
                    tmp.push(make_pair(curr.first,curr.second+1));
                }
            
            q.pop();
            if(q.empty()){
                count++;
                while(!tmp.empty()){
                    q.push(tmp.front());
                    tmp.pop();
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count-1;
        
    }
};