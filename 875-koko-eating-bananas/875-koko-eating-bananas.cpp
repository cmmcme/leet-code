class Solution {
public:
    int result;
    int calculate(vector<int>& piles, int h, int mid) {
        int count = 0;
        for(int i = 0; i < piles.size(); ++i) {
            count = count + (piles[i] / mid) + (piles[i] % mid == 0 ? 0 : 1);
        }
        if(count > h) return 1; // 숫자가 늘어나야함
        else return -1; // 줄어들어야함
    }
    void binarySearch(vector<int>& piles, int l, int r, int h) {
        if(l > r) return ;
        
        int mid = (l + r) / 2;
        
        int res = calculate(piles, h, mid);
        
        if(res > 0) binarySearch(piles, mid + 1, r, h);
        if(res < 0) {
            result = min(result, mid);
            binarySearch(piles, l, mid - 1, h);
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size()) return -1;
        int mmax = 0;
        for(int i = 0; i < piles.size(); ++i) mmax = max(piles[i], mmax);
        result = mmax;
        binarySearch(piles, 1, mmax, h);
        return result;
    }
};