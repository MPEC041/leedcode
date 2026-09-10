class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Check if the next element is larger
            if (nums[mid] < nums[mid + 1]) {
                // Peak lies to the right side
                low = mid + 1;
            } else {
                // Peak lies to the left side (including mid)
                high = mid;
            }
        }
        
        // At the end of the loop, 'low' and 'high' will converge to the peak element index
        return low;
    }
};
