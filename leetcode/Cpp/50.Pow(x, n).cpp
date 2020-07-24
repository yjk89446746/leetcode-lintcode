class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            return myPow(1/x,-(n+1))*(1/x);
        if(n==0)
            return 1;
        double res = myPow(x,n/2);
        res *= res;
        if(n&1)
            res *= x;
        return res;
    }
};
