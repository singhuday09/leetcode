class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
     int sum=0;
     int n=nums.size();
        for(int k=1;k<=n;k++){
            if(n%k!=0){
                continue;
            }
            int prevmax=INT_MIN;
              bool valid = true;
            for(int i=0;i<n;i=i+k){
                int mn=INT_MAX;
                int mx=INT_MIN;
                 int x=0;
                for(int j=i;j<i+k;j++){
                     int s = (j == i + k - 1) ? i : j + 1;
                    if(nums[j]>nums[s])x++;
                   mx=max(mx,nums[j]);
                   mn=min(mn,nums[j]);

                }
 
                if(x>1){
                    valid=false;
                    break;
                }
                if(i>0 && prevmax>mn){
                    valid=false;
                    break;
                }
                else{
                    prevmax=mx;
                }
            }
            if(valid) sum+=k;
           
        }
               return sum;
    }
};


