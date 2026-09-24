class Solution {
public:
   int checknums(int val){
       int sum=0;
       while(val>0){
          sum+=val%10;
          val=val/10;
       }
       return sum;
   }
    int smallestIndex(vector<int>& nums) {
      int small=INT_MAX;
      for(int i=0;i<nums.size();i++){
        if( checknums(nums[i])==i){
            small=min(small,i);
        }
          
      } 
      if(small==INT_MAX)return -1; 
      return small;
    }
};