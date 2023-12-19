class Solution {
public:
    int solve(int n,int k,vector<int> &arr){
        if(n==0)return k%arr[0]==0;
        
        if(k>=arr[n])return solve(n,k-arr[n],arr)+solve(n-1,k,arr);
        return solve(n-1,k,arr);
    }
    int change(int k, vector<int>& arr) {
        int n=arr.size();
        // return solve(n-1,k,arr);
        vector<vector<int>> dp(n,vector<int>(k+1,0));

        for(int i=0;i<=k;i++){
            if(i%arr[0]==0)dp[0][i]=1;
        }
       

        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                if(arr[i]<=j)dp[i][j]=dp[i][j-arr[i]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][k];

    }
};