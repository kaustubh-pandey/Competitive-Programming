//O(n^2) bottom up DP
/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return true;
        }
        bool dp[n];
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int k=1;k<=i;k++){
                if(dp[i-k] && nums[i-k]>=k){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};*/
//O(n) greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return true;
        }
        int curr_idx = n-1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]+i >= curr_idx){
                curr_idx = i;
            }
        }
        return curr_idx == 0;
    }
};