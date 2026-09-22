class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        int sum = 0;
        for(int i = 0; i < 101; i++) // Updated to 101 to check the full range
        {
            if(freq[i] == 1)
            {
                sum = sum + i;
            }
        }
        return sum;
    }
};
