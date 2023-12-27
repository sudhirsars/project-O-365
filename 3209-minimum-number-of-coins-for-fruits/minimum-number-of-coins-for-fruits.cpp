class Solution {
public:
int dp[1001];
int n;
int solve(vector<int> &prices,int ind){
    if(ind>=n){
        return 0;
    }
    if(ind==n-1)return prices[ind];
    if(dp[ind]!=-1)return dp[ind];
    int c=prices[ind];
    int p=INT_MAX;
    for(int i=ind+1;i<min(n+1,2*ind+3);i++){
        p=min(p,solve(prices,i));
    }
    return dp[ind]=p+c;
}
    int minimumCoins(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0);
    }
};