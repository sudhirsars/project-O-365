class Solution {
public:

    int solve(int n,bool flag, vector<int> &p){
        if(n==p.size())return 0;
        
        if(flag){
            return max(-p[n]+solve(n+1,!flag,p),solve(n+1,flag,p));
        }
        return max(p[n]+solve(n+1,!flag,p),solve(n+1,flag,p));
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        // return solve(0,1,p);

        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int flag=1;flag>=0;flag--){
                if(flag){
                    dp[i][flag]= max(-p[i]+dp[i+1][!flag],dp[i+1][flag]);
                }
                else dp[i][flag]=max(p[i]+dp[i+1][!flag],dp[i+1][flag]);
            }
        }
    return dp[0][1];
    }
};