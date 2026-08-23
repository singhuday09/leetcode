class Solution {
public:
     const long long MOD=1e9+7;
    long long pow(int x,long long n){
        if(n==0)return 1;
        long long half=pow(x,n/2);
        if(n%2==0)return (half*half)%MOD;
        else return (x*half*half)%MOD;
    }
   
    int countGoodNumbers(long long n) {
      long long evenpos=(n+1)/2;
      long long oddpos=n/2;
      return (int)((pow(5,evenpos)*pow(4,oddpos))%MOD);  
    }
};