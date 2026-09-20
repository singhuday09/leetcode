class Solution {
public:
    int reverseDegree(string s) {
      int sum=0;
      int diff=0;
      for(int i=0;i<s.size();i++){
        int diff=s[i]-'a';
        int revidx=26-diff;
        int product=revidx*(i+1);
        sum+=product;
      }  
      return sum;
    }
};