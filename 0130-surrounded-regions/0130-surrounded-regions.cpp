class Solution {
  public:
  
int delrow[4] = {-1, 0, 1, 0};
int delcol[4] = {0, 1, 0, -1};
   
   void dfs(int row,int col,vector<vector<char>>& grid, vector<vector<int>>&vis){
       vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
       
       for(int i=0;i<4;i++){
           int nrow=row+delrow[i];
           int ncol=col+delcol[i];
           if(ncol>=0 && ncol<m && nrow>=0 && nrow<n &&!vis[nrow][ncol] && grid[nrow][ncol]=='O'){
               dfs(nrow,ncol,grid,vis);
           }
       }
       
   }
  
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>vis(n,(vector<int>(m,0)));
       
       //travel first and last row;
       for(int j=0;j<m;j++){
           if(grid[0][j]=='O' && !vis[0][j]){
               dfs(0,j,grid,vis);
           }
           if(grid[n-1][j]=='O' && !vis[n-1][j]){
               dfs(n-1,j,grid,vis);
           }
       }
       
       
       for(int i=0;i<n;i++){
           if(grid[i][0]=='O' && !vis[i][0]){
               dfs(i,0,grid,vis);
           }
           if(grid[i][m-1]=='O' && !vis[i][m-1]){
               dfs(i,m-1,grid,vis);
           }
       }
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
             if(!vis[i][j] && grid[i][j]=='O'){
                 grid[i][j]='X';
             }  
           }
       }
      
       
        
    }
};