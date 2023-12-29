class Solution {
public:

    // int solve(int i,int pre,vector<int> &nums){
    //     if(i<0)return 0;
    //     int ans=0;
    //     if(pre==n || nums[i]<nums[pre])ans=1+solve(i-1,i,nums);
    //     ans=max(ans,solve(i-1,pre,nums));
    //     return ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // return solve(n-1,n,nums); 
        vector<int>dp(n,1);

        for(int i=1;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[pre]<nums[i] && dp[i]<1+dp[pre])dp[i]=1+dp[pre];
            }
        }
        int ans=0;
        for(auto it:dp)ans=max(ans,it);
        return ans;

    }
};