class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i=0;
        while(i<n){
            if(formula[i] == '('){
                st.push(unordered_map<string, int>());
                i++;
            } else if(formula[i] == ')'){
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;
                string mult;
                while((i<n) && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }
                if(!mult.empty()){
                    int multInteger = stoi(mult);
                    for(auto &it : curr){
                        string element = it.first;
                        int count = it.second;
                        curr[element] = count*multInteger;
                    }
                }
                for(auto &it : curr){
                    string element = it.first;
                    int count = it.second;
                    st.top()[element] += count;
                }
            } else{
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currElement.push_back(formula[i]);
                    i++;
                }
                string currCount;
                while(i<n && isdigit(formula[i])){
                    currCount.push_back(formula[i]);
                    i++;
                }
                int currCountInteger = currCount.empty()?1 : stoi(currCount);
                st.top()[currElement] += currCountInteger;
            }
        }
        map<string, int> sortedMap(begin(st.top()), end(st.top()));
        string result;
        for(auto &it : sortedMap){
            string element = it.first;
            result += element;
            int count = it.second;
            if(count>1)
                result += to_string(count);
        }
        return result;
    }
};