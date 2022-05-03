class Solution {
public:
    bool isOpenChar(char ch) {
    if(ch == '(') return true;
    if(ch == '[') return true;
    if(ch == '{') return true;
    
    return false;
}

bool isMatched(char top, char now) {
    if(top == '(' && now == ')') return true;
    if(top == '[' && now == ']') return true;
    if(top == '{' && now == '}') return true;
    
    return false;
}
    
    bool isValid(string s) {
    stack<int> st;
    for(int i = 0 ; i < s.size(); ++i) {
        char ch = s[i];
        if(isOpenChar(ch)) st.push(ch);
        else {
            if(st.size() == 0) return false;
            if(isMatched(st.top(), ch)) st.pop();
            else return false;
        }
    }
    return st.size() == 0;    
    }
};