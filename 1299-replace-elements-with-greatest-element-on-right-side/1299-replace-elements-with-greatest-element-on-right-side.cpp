class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    vector<int> res;
    res.resize(arr.size());
        
    int mmax = -1;
    for(int i = arr.size() - 1; i >= 0 ; --i) {
        res[i] = mmax;
        mmax = max(mmax, arr[i]);
    }
        return res;
    }
};