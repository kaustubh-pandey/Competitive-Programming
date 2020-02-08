//bitmasking approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long long n = (1LL<<nums.size())-1; 
        vector<vector<int>> res;
        while(n){
            long long copy = n;
            vector<int> temp;
            int count = 0;
            while(copy){
                if(copy&1){
                  temp.push_back(nums[count]);  
                }
                count++;
                copy = copy>>1;
            }
            res.push_back(temp);
            n--;
        }
        res.push_back({});
        return res;
    }
//using backtracking and memoisation (dp)
class Solution {
public:
    void f(vector<vector<int>> &res,vector<int> nums,map<vector<int>,bool> &dp){
        if(nums.size()==0){
            return;
        }
        if(dp[nums]){
            return;
        }
        res.push_back(nums);
        dp[nums]=true;
        for(int i=0;i<nums.size();i++){
            vector<int> tmp;
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    tmp.push_back(nums[j]);
                }
            }
            f(res,tmp,dp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        map<vector<int>,bool> dp;
        f(res,nums,dp);
        res.push_back({});
        return res;
    }
};