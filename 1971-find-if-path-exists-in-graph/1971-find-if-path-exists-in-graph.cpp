class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int>q;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        q.push(source);
        vis[source]=1;
      while(!q.empty()){
          int node=q.front();
           q.pop();
           for(auto it:adj[node]){
               if(!vis[it]){
                vis[it]=1;
                q.push(it);
               }
           }
       
      }
      if(vis[destination]==1)return true;
      return false;
    }
};