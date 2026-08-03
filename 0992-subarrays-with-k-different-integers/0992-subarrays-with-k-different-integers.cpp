class Solution {
public:

   int fun(vector<int>& nums, int k){
      int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
                
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return fun(nums,k)-fun(nums,k-1);

    }
};