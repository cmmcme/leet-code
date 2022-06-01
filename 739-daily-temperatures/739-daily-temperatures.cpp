class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < temperatures.size(); ++i) {
            while(!st.empty()) {
                int topIndex = st.top();
                if(temperatures[topIndex] < temperatures[i]) {
                    res[topIndex] = i - topIndex;
                    st.pop();
                } else {
                    break;
                }
            }
            
            st.push(i);
        }
        return res;
    }
};