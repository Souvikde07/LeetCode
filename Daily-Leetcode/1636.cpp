class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        for (int n : nums) {
            frequencyMap[n]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (frequencyMap[a] != frequencyMap[b]) {
                return frequencyMap[a] < frequencyMap[b];
            }
            return a > b;
        });
        return nums;
    }
};