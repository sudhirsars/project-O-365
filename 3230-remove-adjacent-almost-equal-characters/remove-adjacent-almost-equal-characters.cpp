class Solution {
public:
    int dp[102][102];
    bool check(char x, char y){
        return (int)x == (int)y ||(int)x == ((int)y)+1 ||((int)x)+1 == (int)y;
    }
    int solve(int i,int j, string w){
        if(i>=j)return 0;
        int ans=1e8;
        if(dp[i][j])return dp[i][j];

            for(int k=i+1;k<=j;k++){
                if(check(w[k],w[k-1])){
                    int t= 1+ solve(i,k-1,w)+ solve(k+1,j,w);
                    ans=min(ans,t);
                }
            }
        
        if(ans==1e8)return dp[i][j]= 0;
        return dp[i][j]= ans;
    }
    int removeAlmostEqualCharacters(string word) {
        memset(dp,0,sizeof(dp));
        return solve(0,word.length()-1,word);
    }
};