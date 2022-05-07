class Solution {
public:
    string str;
    bool palindrome(int l, int r) {
        if(l >= r) return true;
        
        if(str[l] == str[r]) return palindrome(l + 1, r - 1);
        
        return false;
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        str = to_string(x);
        
        return palindrome(0, str.size() - 1);
    }
};