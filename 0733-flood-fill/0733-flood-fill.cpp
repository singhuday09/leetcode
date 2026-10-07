class Solution {
public:
 int dr[4]={-1,0,1,0};
 int dc[4]={0,1,0,-1};
  void dfs(vector<vector<int>>& image, int sr, int sc, int color,int srccolor){
    if(sr<0 || sr>=image.size()|| sc<0 || sc>=image[0].size()){
        return ;
    }
    if(image[sr][sc]!=srccolor)return ;
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int nrow=sr+dr[i];
            int ncol=sc+dc[i];
            dfs(image,nrow,ncol,color,srccolor);

        }
    
    return ;
  }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int srccolor = image[sr][sc];
        if(srccolor == color)
            return image;
         dfs(image,sr ,sc,color,srccolor);
         return image;
    }
};