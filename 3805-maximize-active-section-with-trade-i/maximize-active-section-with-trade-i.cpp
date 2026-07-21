#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }

        
        std::vector<std::pair<char, int>> blocks;
        
        int n = s.length();
        if (n == 0) return 0;

        // Group into blocks
        int i = 0;
        while (i < n) {
            char type = s[i];
            int len = 0;
            while (i < n && s[i] == type) {
                len++;
                i++;
            }
            blocks.push_back({type, len});
        }

        int max_gain = 0;
        int num_blocks = blocks.size();

        
        for (int j = 0; j < num_blocks; j++) {
            if (blocks[j].first == '1') {
               
                if (j > 0 && j < num_blocks - 1) {
                    int gain = blocks[j - 1].second + blocks[j + 1].second;
                    max_gain = std::max(max_gain, gain);
                }
            }
        }

        return initial_ones + max_gain;
    }
};
