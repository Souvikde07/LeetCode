class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        int i = 0;
        while (i<j)
        {
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;
    }
};

// using c++ functions
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(word.begin(),word.begin() + word.find(ch) + 1);
        return word;
    }
};