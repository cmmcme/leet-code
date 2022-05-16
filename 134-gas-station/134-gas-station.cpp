class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0;
        int start = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);
            
            totalSum += (gas[i] - cost[i]);
            if(sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return totalSum < 0 ? -1 : start;
    }
};