class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        int n=arr.size();
        if(k>n)return -1;
        if(k==n)return 0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.second<b.second;
        });
      int size=v.size();
      for(auto &p:v){
        if(k>=p.second){
            k-=p.second;
            size--;
        }
        else break;
      }
      return size;
        
      
    }
};