#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 特殊情况
        if (n <= 2) return n;

        // dp 数组，dp[i] 表示到第 i 阶的方法数
        vector<int> dp(n + 1, 0);

        // base case
        dp[1] = 1;
        dp[2] = 2;

        // 从小问题推到大问题
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
