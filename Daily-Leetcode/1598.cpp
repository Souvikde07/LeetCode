//Approach - 1
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int depth = 0;
        for(int i = 0; i < n; i++){
            if(logs[i] == "../"){
                depth = max(0, depth-1); //if depth=0, dont decrement depth
            } else if(logs[i] == "./"){
                continue;
            } else{
                depth++;
            }
        }
        return depth;
    }
};
//Approach - 2
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string &log : logs){
            if(log == "../"){
                if(!st.empty()){
                    st.pop();
                }
            } else if(log != "./"){
                st.push(log);
            }
        }
        return st.size();
    }
};