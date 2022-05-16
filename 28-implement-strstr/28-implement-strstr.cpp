class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
        for(int i = 0; i < haystack.size(); ++i) {
            if(haystack[i] != needle[0]) continue;
            int index = i;
            while((index - i) != needle.size() && index != haystack.size()) {
                if(haystack[index] != needle[index - i]) break;
                index++;
            }
            if((index - i) == needle.size()) return i;
        }
        
        return -1;
    }
};