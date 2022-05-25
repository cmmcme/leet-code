class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == 0) return 0;
        
        if(n < 0) {
            n = abs(n);
            x = 1/x;
        }
        
        double res = 1.0;
        while(n) {
            if(n % 2 == 0) {
                x *= x;
                n = n / 2;
            } else {
                n = n - 1;
                res *= x;
            }
        }

        return res;
    }
};