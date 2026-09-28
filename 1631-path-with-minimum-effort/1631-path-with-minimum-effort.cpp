class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
         
      priority_queue<pair<int, pair<int,int>>,
                     vector<pair<int, pair<int,int>>>,
                     greater<pair<int, pair<int,int>>>> pq;
         
         pq.push({0,{0,0}});
         
         int dr[]={-1,0,1,0};
         int dc[]={0,1,0,-1};
         
         while(!pq.empty()){
             auto it=pq.top();
             pq.pop();
             int eff=it.first;
             int r=it.second.first;
             int c=it.second.second;
            
             if(r==n-1 && c==m-1)return eff;
             
             for(int i=0;i<4;i++){
                 int nrow=dr[i]+r;
                 int ncol=dc[i]+c;
                 
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                     int neweffort=max(abs(heights[nrow][ncol]-heights[r][c]),eff);
                     
                     if(neweffort<effort[nrow][ncol]){
                     effort[nrow][ncol] = neweffort;
                     pq.push({neweffort,{nrow,ncol}});
                     }
                 }
             }
         }
    
        return 0; 
    }
};