#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        
        std::unordered_map<int, int> prefixSumCounts;
        
        
        prefixSumCounts[0] = 1;
        
        int currentSum = 0;
        int totalSubarrays = 0;
        
        for (int num : nums) {
            
            currentSum += num;
            
            
            if (prefixSumCounts.find(currentSum - k) != prefixSumCounts.end()) {
                totalSubarrays += prefixSumCounts[currentSum - k];
            }
            
            
            prefixSumCounts[currentSum]++;
        }
        
        return totalSubarrays;
    }
};
