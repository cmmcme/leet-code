class Solution {
public:
    int getAmount(char ch) {
        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        if(ch == 'M') return 1000;
        
        return -1;
    }
    int romanToInt(string s) {
        int index = 0;
        int res = 0;
        int before = 0;
        while(index < s.size()) {
            int val = getAmount(s[index++]);
            res += val;
            if(val > before) {
                res = res - before - before; 
            }
            before = val;
        }
        
        return res;
    }
};