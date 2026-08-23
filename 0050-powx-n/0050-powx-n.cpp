class Solution {
public:
      double pow(double x,long long n){
        if(n==1)return x;
        if(n==0)return 1;
        double half=pow(x,n/2);
        if(n%2==0){
            return half*half;
        }
        else
        return x*half*half;
      }
    double myPow(double x, int n) {
        long long N=n;
       if(N<0)return pow(1/x,N);
       return pow(x,N);
    }
};