class Solution {
public:

    int solve(int i,int k,vector<int>& nums){
        if(k==0)return 0;
        if(i>=nums.size())return -1e5;
        

        return max(1+solve(i+1,k-nums[i],nums),solve(i+1,k,nums));
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // int x=solve(0,target,nums);
        // return x>0?x:-1;
        int n=nums.size();
        int dp[n+1][target+1];
        int k=target;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++){
            dp[n][i]=-1e5;
        }

        for(int i=n-1;i>=0;i--){
            for(int tar=1;tar<=k;tar++){
                int t=dp[i+1][tar];
                if(tar>=nums[i])t=max(t,1+dp[i+1][tar-nums[i]]);
                dp[i][tar]=t;
            }
        }
        int x=dp[0][target];
        return x>0?x:-1;
    }
};