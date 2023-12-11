class Solution {
public:
    int dp[1002][1002];
    // int solve(string &x,string &y,int i,int j){
    //     if(i<0 || j<0){
    //         return 0;
    //     }
    //     if(dp[i][j])return dp[i][j];
    //     if(x[i]==y[j]){
    //         return dp[i][j]=1+solve(x,y,i-1,j-1);
    //     }
    //     return dp[i][j]=max(solve(x,y,i-1,j) ,solve(x,y,i,j-1));
    // }
    int longestCommonSubsequence(string x, string y) {
        int n=x.length();
        int m=y.length();
    
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(x[i]==y[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
                ans=max(ans, dp[i+1][j+1]);

            }
        }
        return dp[n][m];
    }
};