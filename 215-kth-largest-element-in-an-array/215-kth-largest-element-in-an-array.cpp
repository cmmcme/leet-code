class Solution {
public:
    int partition(vector<int>& vec, int left, int right) {
    int pivot = vec[right];
    // cout<<"pivot : "<<right<<' '<<pivot<<endl;
    int currentSmallLocation = left;
    for(int i = left; i <= right; ++i) {
        if(vec[i] <= pivot) swap(vec[currentSmallLocation++], vec[i]);
    }
    
//     for(int i = 0; i < 7; ++i) cout<<vec[i]<<' ';
//     cout<<endl;
//     cout<<"current : "<<currentSmallLocation<<endl;

    return currentSmallLocation - 1;
}

int quickSelection(vector<int>& vec, int left, int right, int k) {
    int pivotPos = partition(vec, left, right);
    if(pivotPos == k - 1) return vec[pivotPos];
    
    if(pivotPos > k - 1) { //내가 찾은 pivot (n 번째) 가 k 보다 클 때, k 번쨰는 left ~ pivotPos - 1 사이에 있을 거임 (왼쪽에 있을 것)
        return quickSelection(vec, left, pivotPos - 1, k);
    } else { // 내가 찾은 pivot (n 번째) 가 k 보다 작을 때, k 번쨰는 pivot + 1 ~ right 사이에 있을거
        return quickSelection(vec, pivotPos + 1, right, k);
    }
    return -1;
}
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelection(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
};