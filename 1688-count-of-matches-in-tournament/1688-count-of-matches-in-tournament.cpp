class Solution {
public:
    int numberOfMatches(int n) {
        int noofmatch=0;
        while(n!=1){
            if(n%2==0){
                noofmatch+=n/2;
                n=n/2;
            }
            else {
                noofmatch+=(n-1)/2;
                n=((n-1)/2)+1;
            }
        }
        return noofmatch;
    }
};