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
          rank[upar_v]++;
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        Disjointset ds(n);
        int cntedges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)==ds.findupar(v))cntedges++;
            else ds.unionbyRank(u,v);
        }
        int cntc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)cntc++;
        }
        if(cntedges>=cntc-1)return cntc-1;
        return -1;
    }
};