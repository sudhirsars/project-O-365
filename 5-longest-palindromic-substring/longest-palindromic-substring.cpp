class Solution {
public:
    auto check(int i, int j,string s){
        int n=s.length();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        // i++;
        // j--;
        return s.substr(i+1 , j - i - 1 );
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string a=check(i,i,s);
            if(a.length()>ans.length())ans=a;
            a=check(i,i+1,s);
            if(a.length()>ans.length())ans=a; 
        }
        return ans;
    }
};