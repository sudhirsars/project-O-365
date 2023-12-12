class Solution {
public:

    vector<vector<int>> dp;
    int solve(int i,int pre_i,vector<int> &nums){
        if(i<0)return 0;

        int pick=0,n_pick=0;
        if(dp[i][pre_i+1])return dp[i][pre_i+1];

        if(pre_i==-1 || nums[i]<nums[pre_i])
            pick=1+solve(i-1,i,nums);
        n_pick=solve(i-1,pre_i,nums);


        return dp[i][pre_i+1]=max(pick,n_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+1,0));
        return solve(nums.size()-1,-1,nums);
    }
};