class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
           int m=grid[0].size();
        int n=grid.size();
       queue<pair<int, pair<int, int>>>q;
       vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
       dist[0][0]=1;
       
       
       int dr[]={-1,-1,0,1,1,1,0,-1};
       int dc[]={0,1,1,1,0,-1,-1,-1};
       if (grid[0][0] == 1 ||
                 grid[n-1][n-1] == 1)
                 return -1;
       
       q.push({1,{0,0}});
       
       while(!q.empty()){
          auto it=q.front();
          q.pop();
          int dis=it.first;
          int r=it.second.first;
          int c=it.second.second;
          if(r==n-1&& c==n-1)return dis;
          
          
          for(int i=0;i<8;i++){
              int nrow=dr[i]+r;
              int ncol=dc[i]+c;
              
              if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol]!=1){
                   if(dist[r][c]+1<dist[nrow][ncol]){
                       dist[nrow][ncol]=dist[r][c]+1;
                       q.push({dist[nrow][ncol],{nrow,ncol}});
                       
                       
                   }   
              }
          }
       }
    return -1;
    }
};