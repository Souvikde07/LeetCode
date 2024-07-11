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