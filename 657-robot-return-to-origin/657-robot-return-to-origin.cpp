class Solution {
public:
    pair<int, int> direct(char c) {
        if(c == 'L') return make_pair(0, 1);
        if(c == 'R') return make_pair(0, -1);
        if(c == 'U') return make_pair(1, 1);
        if(c == 'D') return make_pair(1, -1);
        
        return make_pair(100,100);
    }
    bool judgeCircle(string moves) {
        int sumArr[2] = {0};
        for(int i = 0; i < moves.size(); ++i) {
            pair<int, int> pa = direct(moves[i]);
            sumArr[pa.first] += pa.second;
        }
        return sumArr[0] ==0 && sumArr[1] == 0;
    }
};