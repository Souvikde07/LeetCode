class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;   // Tracks the imbalance between opening and closing brackets

        // Traverse each character in the string
        for (const char& ch : s) {
            if (ch == ']') {
                // If a closing bracket is encountered
                if (imbalance == 0) {
                    // If no opening bracket is available, we need to "swap" it later
                    imbalance++;  // Mark this as a new imbalance
                } else {
                    // Otherwise, there's an unmatched opening bracket available, balance it
                    imbalance--;
                }
            } else {
                // If an opening bracket is encountered, increase the imbalance
                imbalance++;
            }
        }

        // The final imbalance is divided by 2 (since one swap fixes two unmatched brackets)
        return (imbalance + 1) / 2;
    }
};
