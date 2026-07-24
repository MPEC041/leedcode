#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }
        
        
        int max_xor_bound = 1;
        while (max_xor_bound <= max_val) {
            max_xor_bound <<= 1;
        }
       
        max_xor_bound = std::max(max_xor_bound, 2048); 

    
        std::vector<bool> unique_nums(max_xor_bound, false);
        std::vector<int> distinct_elements;

        
        for (int num : nums) {
            if (!unique_nums[num]) {
                unique_nums[num] = true;
                distinct_elements.push_back(num);
            }
        }

        
        std::vector<bool> pairs_xor(max_xor_bound, false);
        for (int i = 0; i < distinct_elements.size(); ++i) {
            for (int j = i; j < distinct_elements.size(); ++j) {
                pairs_xor[distinct_elements[i] ^ distinct_elements[j]] = true;
            }
        }

        
        std::vector<bool> triplets_xor(max_xor_bound, false);
        for (int i = 0; i < max_xor_bound; ++i) {
            if (pairs_xor[i]) {
                for (int val : distinct_elements) {
                    triplets_xor[i ^ val] = true;
                }
            }
        }

        
        int unique_triplet_count = 0;
        for (int i = 0; i < max_xor_bound; ++i) {
            if (triplets_xor[i]) {
                unique_triplet_count++;
            }
        }

        return unique_triplet_count;
    }
};
