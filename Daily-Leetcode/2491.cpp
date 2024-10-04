#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        long long sum = std::accumulate(skill.begin(), skill.end(), 0LL);
        int n = skill.size();

        if (n == 2) {
            return static_cast<long long>(skill[0]) * skill[1];
        }

        if (sum % (n / 2) != 0) {
            return -1;
        }

        std::sort(skill.begin(), skill.end());

        int score = skill[0] + skill[n - 1];
        long long result = 0;

        for (int i = 0; i < n / 2; ++i) {
            int l = skill[i], r = skill[n - 1 - i];
            if (l + r != score) {
                return -1;
            }
            result += static_cast<long long>(l) * r;
        }

        return result;
    }
};