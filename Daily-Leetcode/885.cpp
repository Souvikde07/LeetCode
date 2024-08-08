class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 1;
        int d = 0;
        int r = rStart, c = cStart;
        result.push_back({r, c});

        while (result.size() < rows * cols) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    r += directions[d][0];
                    c += directions[d][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                d = (d + 1) % 4;
            }
            ++steps;
        }

        return result;
    }
};