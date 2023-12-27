class Solution {
public:
    // int solve(int i,vector<int>&p){
    //     if(i>=p.size())return 0;

    //     int ans=1e8;
    //     int n=p.size();
    //     for(int k=i+1; k < min(n+1, 2*i+3) ;k++){
    //         ans=min(ans,p[i]+solve(k,p));
    //     }
    //     return ans;
    // }   
    int minimumCoins(vector<int>& p) {
        int n=p.size();

        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int ans=1e8;
            for(int k=i+1; k < min(n+1, 2*i+3) ;k++){
                ans=min(ans,p[i]+dp[k]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};