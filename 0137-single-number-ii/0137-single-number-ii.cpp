class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        // Loop through all 32 possible bit positions of an integer
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            
            // Count how many numbers have the i-th bit set to 1
            for (int num : nums) {
                if ((num >> i) & 1) {
                    bitSum++;
                }
            }
            
            // If the bit sum is not a multiple of 3, it belongs to the single number
            if (bitSum % 3 != 0) {
                ans |= (1 << i);
            }
        }
        
        return ans;
    }
};
