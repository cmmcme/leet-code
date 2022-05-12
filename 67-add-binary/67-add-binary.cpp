class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        int plus = 0;
        string res = "";
        while(j >= 0 || i >= 0) {
            if(j < 0) {
                int sum = a[i] - '0'+ plus;
                plus = sum / 2;
                res = to_string(sum % 2) + res;
            } else if(i < 0) {
                int sum = b[j] - '0' + plus;
                plus = sum / 2;
                res = to_string(sum % 2) + res;
            } else {
                int sum = a[i] - '0' + b[j] - '0' + plus;
                plus = sum / 2;
                res = to_string(sum % 2) + res;
            }
            
            i--;
            j--;
        }
        if(plus != 0) return to_string(plus) + res;
        return res;
    }
};