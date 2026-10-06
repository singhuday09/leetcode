class Solution {
public:
    int help(vector<int>& arr,int k,int i,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
         int maximum=0;
       
         int finalans=0;
        for(int j=i;j-i+1<=k && j<arr.size();j++){
            int length=j-i+1;
            maximum=max(maximum,arr[j]);
            int currsum=maximum*length;
           int ans= help(arr,k,j+1,dp);
            finalans=max(finalans,currsum+ans);

        }
        return dp[i]= finalans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
      return help(arr,k,0,dp);  
    }
};