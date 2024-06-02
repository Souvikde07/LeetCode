// double pointer approach :
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r=s.size()-1;
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
// Recursive Approach
class Solution {
public:
    void reverse(vector<char>&s, int left, int right){
        if(left>=right) return;
        swap(s[left],s[right]);
        reverse(s,left+1,right-1);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }
};