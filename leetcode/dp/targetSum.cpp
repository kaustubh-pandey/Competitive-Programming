class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //No. of subsets with given diff
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum<S || (sum+S)%2){
            return 0;
        }
        int target = (sum+S)/2;
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){cnt++;}
        }
        //count no. of subsets with given target
        int dp[n+1][target+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
                if(i>0 && j>0){
                    if(nums[i-1]<=j && nums[i-1]!=0){
                        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=target;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][target]*(1<<cnt);
    }
};