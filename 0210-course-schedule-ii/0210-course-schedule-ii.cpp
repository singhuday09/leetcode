class Solution {
public:
       
       vector<vector<int>>adj;
bool help(int node,vector<int>&topo,vector<int>&vis,vector<int>&pathvis){

   vis[node]=1;
   pathvis[node]=1;
    for(auto it:adj[node]){
        if(pathvis[it]==1 )return false;
        if(!vis[it]){
            if(!help(it,topo,vis,pathvis))return false;

        }
        
    }
    pathvis[node]=0;
    topo.push_back(node);
    return true;
}

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<int>topo;
        vector<int>pathvis(n,0);


        vector<int>vis(n,0);
     
      adj.resize(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
           if( !help(i,topo,vis,pathvis))return {};
            }
        }
        reverse(topo.begin(),topo.end());
        return topo;
    }
};