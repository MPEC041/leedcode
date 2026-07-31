#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
       
        return minHeap.top();
    }
};
// class Solution {
// public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[k+1]==nums[i]){
//              return nums[i];
//         }
        
//        }
//    return -1;  }
   
       
// };