class Solution {
public:

    //  int f(int i,string &s,int j,string &p,vector<vector<int>>&dp){
    //     if(i==0 && j==0)return true;
    //     if(j==0 && i>0)return false;
    //     if(i==0 && j>0){
    //         for(int ii=1 ;ii<=j ;ii++){
    //            if(p[ii-1]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] !=-1) return dp[i][j];

    //     if(s[i-1]==p[j-1] || p[j-1]=='?'){
    //         return dp[i][j]= f(i-1,s,j-1,p,dp);
    //     }
    //     if(p[j-1]=='*'){
    //         return dp[i][j]= f(i-1,s,j,p,dp)||f(i,s,j-1,p,dp);
    //     }
    //     return dp[i][j]= false;
    //  }

    bool isMatch(string s, string p) {
        // int m=s.size();
        // int n=p.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return f(m,s,n,p,dp);
        int m=s.size();
        int n=p.size();

        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;

        for(int i=1;i<=m;i++){
            dp[i][0]=false;
        }

        for(int j=1;j<=n;j++){
            bool flag=true;

            for(int k=1;k<=j;k++){
                if(p[k-1]!='*')flag=false;
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')dp[i][j]=( dp[i-1][j] || dp[i][j-1]) ;
                else dp[i][j]=false;
            }
        }
        
        return dp[m][n];

    }
};