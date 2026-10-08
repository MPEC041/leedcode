
    int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right = 0;
    
    
    for (right = 0; right < numsSize; right++) {
        
        if (nums[right] == 0) {
            k--;
        }
        
        
        if (k < 0) {
            if (nums[left] == 0) {
                k++;
            }
            left++;
        }
    }
    
  
    return right - left;
}
