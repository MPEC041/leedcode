#include <vector>

class Solution {
private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    // Precompute Pascal's Triangle for combination coefficients
    void precomputeCombinations(int n) {
        table.assign(n + 1, std::vector<long long>(n + 1, 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(std::vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        std::vector<int> left, right;

        // Partition elements into left and right subtrees
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int l_size = left.size();
        int r_size = right.size();

        // Recursively compute ways for left and right subtrees
        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        // Interleave left and right subtree sequences
        long long current_ways = table[l_size + r_size][l_size];

        return (((current_ways * left_ways) % MOD) * right_ways) % MOD;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        precomputeCombinations(n);
        
        // Subtract 1 to exclude the original arrangement itself
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
