class Solution {
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
};