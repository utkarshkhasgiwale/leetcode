#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long x = 0;
        long long y = static_cast<long long>(std::sqrt(c));

        while (x <= y) {
            long long sum = x * x + y * y;
            if (sum > c) {
                y--;
            } else if (sum < c) {
                x++;
            } else {
                return true;
            }
        }

        return false;
    }
};