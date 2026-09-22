class Solution {
public:
 void dfs(vector<vector<int>>&ans,int node,int target,vector<int>&path,vector<vector<int>>& graph){
    path.push_back(node);
    if(node==target){
        ans.push_back(path);
        path.pop_back();
        return ;
    }
    for(auto it:graph[node]){
       dfs(ans,it,target,path,graph);
    }
    path.pop_back();

  }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>path;
        vector<vector<int>>ans;
        dfs(ans,0,n-1,path,graph);
        return ans;
    }
};