class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        int tempX = x;
        long long int reverseX = 0;
        while(tempX) {            
            reverseX = (reverseX * 10) + (tempX % 10);
            tempX = tempX / 10;
        }
        return x == reverseX;
    }
};