class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
           vector<int>dist(n,INT_MAX);
     vector<vector<pair<int,int>>>adj(n);
     for(auto it:flights){
         int u=it[0];
         int v=it[1];
         int w=it[2];
         adj[u].push_back({v,w});
        
     }
     dist[src]=0;
     
     queue<pair<int,pair<int,int>>>q;
     q.push({0,{src,0}});
     
     while(!q.empty()){
         auto it=q.front();
         q.pop();
         int node=it.second.first;
         int w8=it.second.second;
         int currk=it.first;
         if(currk>k)continue;
         
         for(auto it:adj[node]){
             int adjnode= it.first;
             int adjw8=it.second;
             
             if(w8+adjw8<dist[adjnode] && currk<=k){
                 dist[adjnode]=w8+adjw8;
                 q.push({currk+1,{adjnode,w8+adjw8}});
             }
         }
     }
     if(dist[dst]==INT_MAX)return -1;
     return dist[dst];
    }
};