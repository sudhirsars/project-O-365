class Solution {
public:
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for(int i=0;i<n-1;i++){
            if(groups[i]==groups[i+1])continue;
            ans.push_back(words[i]);
        }
        ans.push_back(words[n-1]);
        return ans;
    }
};