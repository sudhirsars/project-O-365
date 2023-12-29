class Solution {
public:
    bool check(string x, string y, int i, int j,vector<int>& groups){
        if(groups[i]==groups[j])return 0;
        int n=x.length();
        int m=y.length();
        if(n!=m)return 0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(x[i]!=y[i])cnt++;
        }
        return cnt==1;
    }
 
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
      vector<int> dp(n,1),par(n,0);
      for(int i=0;i<n;i++)par[i]=i;
      int mx=0;
      int mx_i=0;
      for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
              if(check(w[i],w[j],i,j,g) && dp[i]<1+dp[j]){
                  dp[i]=1+dp[j];
                  par[i]=j;
                  if(mx<dp[i]){
                      mx=dp[i];
                      mx_i=i;
                  }
                  
              }
          }
      }
      vector<string> ans;
      int i=mx_i;
        ans.push_back(w[i]);
      while(par[i]!=i){
          ans.push_back(w[par[i]]);
            i=par[i];
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};