class Solution {
public:

// bool checkpalindrome(string pal){
//     int i=0;
//     int j=pal.size()-1;
//     bool flag=true;
//     while(i<=j){
//      if(pal[i]!=pal[j]){
//        return false;
//     }
    
//     i++;
//     j--;
//     }
//     return true;
// }

// int solve(string &s,string&ans,int i){
//     if(i>s.size()-1){
//         if(checkpalindrome(ans)){
//          return ans.size();
//           }
//           return 0;
//     }
//     int notpick=solve(s,ans,i+1);
//      int pick=solve(s,ans+=s[i],i+1);
//      ans.pop_back();
  
//     return max(pick,notpick);
// }

//     int longestPalindromeSubseq(string s) {
//       string ans="";
//        return solve(s,ans,0); 

int helper(string &s,int i,int j, vector<vector<int>>&dp){
    if(i>j){
        return 0;
    }

    if(i==j){
      return 1;

    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
     
     if(s[i]==s[j]){
        return dp[i][j]=2+helper(s,i+1,j-1,dp);
     }
     return dp[i][j]=max(helper(s,i+1,j,dp),helper(s,i,j-1,dp));

}

 int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return helper(s,0,n-1,dp);

    }
};