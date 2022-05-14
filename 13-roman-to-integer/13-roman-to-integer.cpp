class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp;
        mp["I"] = 1;
        mp["X"] = 10;
        mp["V"] = 5;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        
        
        int index = 0;
        int res = 0;
        int before = 0;
        while(index < s.size()) {
            string sizeOne = s.substr(index, 1);
            string sizeTwo = s.substr(index, 2);
            if(mp[sizeOne]) {
                res += mp[sizeOne];
                before = mp[sizeOne];
                index++;
            }
                    
            if(mp[sizeTwo]) {
                res -= before;
                res += mp[sizeTwo];
                index++;
            }
        }
        
        return res;
    }
};