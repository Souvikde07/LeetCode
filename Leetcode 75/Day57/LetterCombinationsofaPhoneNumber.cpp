#include <unordered_map>
#include <vector>
#include <string>

class Solution {
    // Mapping of digits to corresponding characters
    std::unordered_map<char, std::string> m;
    
    // Resulting combinations
    std::vector<std::string> output;

    // Depth-first search for generating combinations
    void dfs(const std::string& digits, int index, std::string& s) {
        // If the end of digits is reached, add the combination to the output
        if (index == digits.size()) {
            output.push_back(s);
            return;
        }

        // Explore all characters corresponding to the current digit
        for (char i : m[digits[index]]) {
            s.push_back(i);            // Choose the character
            dfs(digits, index + 1, s);  // Explore further
            s.pop_back();               // Backtrack to try other characters
        }
    }

public:
    // Constructor: Initialize the digit-to-character mapping
    Solution() : m{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}} {}

    // Main function to generate letter combinations
    std::vector<std::string> letterCombinations(std::string digits) {
        std::string s;
        // If digits is not empty, start the depth-first search
        if (!digits.empty()) dfs(digits, 0, s);
        return output;
    }
};