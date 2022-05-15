class Solution {
public:
    string getBuzzMessage(int n) {
        if(n % 5 == 0 && n % 3 == 0) return "FizzBuzz";
        if(n % 3 == 0) return "Fizz";
        if(n % 5 == 0) return "Buzz";
        
        return to_string(n);
    }
    
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; ++i) {
            res.push_back(getBuzzMessage(i));
        }
        return res;
    }
};