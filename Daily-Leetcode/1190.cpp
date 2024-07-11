class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<std::string> st;
        std::string current;
        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current.clear();
            } else if (c == ')') {
                std::reverse(current.begin(), current.end());
                if (!st.empty()) {
                    current = st.top() + current;
                    st.pop();
                }
            } else {
                current.push_back(c);
            }
        }
        return current;
    }
};
//Approach-2-TC-O(n*n) - Simple Method using stack
// TC = O(n*n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkipLength;
        string result;
        for(char &ch: s){
            if(ch == '('){
                lastSkipLength.push(result.length());
            } else if(ch == ')'){
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(begin(result) + l, end(result));
            } else{
                result.push_back(ch);
            }
        }
        return result;
    }
};