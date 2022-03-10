class Solution {
public:
    string frequencySort(string s) {
        int countList[200] = {0};
        for(char ch : s) ++countList[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            if(countList[a] == countList[b]) return a < b;
            return countList[a] > countList[b];
        });
        
        return s;
    }
};