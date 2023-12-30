class Solution {
public:
    int solve(int n){
        if(n==1 ||n==0)return 1;
        int ans=0;
        for(int k=0;k<n;k++){
            ans+=solve(k)*solve(n-k-1);
        }
        return ans;
    }
    int numTrees(int n) {
        // return solve(n);
        vector<int> dp(n+1,1);

        for(int i=2;i<=n;i++){
            int ans=0;
            for(int k=0;k<i;k++){
                ans+=dp[k]*dp[i-k-1];
            }
            dp[i]= ans;
        }
        return dp[n];
    }
};