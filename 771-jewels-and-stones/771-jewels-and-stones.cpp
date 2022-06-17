class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int alpha[256] = {0};
        int count = 0;
        for(int i = 0; i < stones.size(); ++i) {
            alpha[stones[i]]++;
        }
        
        for(int i = 0; i < jewels.size(); ++i) {
            count += alpha[jewels[i]];
        }
        return count;
    }
};