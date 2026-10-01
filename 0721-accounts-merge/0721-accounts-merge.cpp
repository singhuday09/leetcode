class Disjointset{
     public:
    vector<int>rank,parent;

    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }

    int findupar(int node){
        if( node==parent[node])return node;
        return parent[node]=findupar(parent[node]);
    }

    void unionbyRank(int u,int v){
        int upar_u=findupar(u);
        int upar_v=findupar(v);
        if(upar_u==upar_v)return ;
        else if(rank[upar_u]<rank[upar_v]){
            parent[upar_u]=upar_v;
        }
        else if(rank[upar_v]<rank[upar_u]){

         parent[upar_v]=upar_u;
        }
        else {
          parent[upar_v]=upar_u;
          rank[upar_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int n=accounts.size();
        Disjointset ds(n); 
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)!=mp.end()){//createed unoin of the current index or the mail index that found in the mp bcoz they belong to the same person
                    ds.unionbyRank(i,mp[mail]);
                }
                else {
                    mp[mail]=i;
                }
            }

        }

        vector<vector<string>>mergedmail(n);
        for( auto it:mp){
            string mail=it.first;
            int node=ds.findupar(it.second);
            mergedmail[node].push_back(mail);
        }

       vector<vector<string>>ans;

        for(int i=0;i<n;i++){
           if(mergedmail[i].size()==0)continue;
           sort(mergedmail[i].begin(),mergedmail[i].end());
           vector<string>temp;
           temp.push_back(accounts[i][0]);
           for(auto it:mergedmail[i]){
            temp.push_back(it);
           }
           ans.push_back(temp);
        }
        return ans;

    }
};