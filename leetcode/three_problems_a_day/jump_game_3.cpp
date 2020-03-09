class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr.size()==0){
            return false;
        }
        bool visited[arr.size()];
        memset(visited,false,sizeof(visited));
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int front_idx = q.front();
            visited[front_idx]=true;
            q.pop();
            if(arr[front_idx]==0){
                return true;
            }
            int l = front_idx-arr[front_idx];
            int r = front_idx+arr[front_idx];
            if(l>=0 && l<arr.size() && !visited[l]){
                q.push(l);
            }
            if(r>=0 && r<arr.size() && !visited[r]){
                q.push(r);
            }
        }
        return false;
        
    }
};