class Solution {
public:

    int help(int amount, vector<int>& coins,int idx,vector<vector<int>>&dp){
        if(amount==0)return 1;
       if(idx == coins.size()) return 0;
       if(dp[idx][amount]!=-1)return dp[idx][amount];
        int take=0;
       if(amount>=coins[idx]){
        take+=help(amount-coins[idx],coins,idx,dp); 
       }
       int nottake=help(amount,coins,idx+1,dp);
  return dp[idx][amount]= take+nottake;

    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return help(amount,coins,0,dp);
    }
};