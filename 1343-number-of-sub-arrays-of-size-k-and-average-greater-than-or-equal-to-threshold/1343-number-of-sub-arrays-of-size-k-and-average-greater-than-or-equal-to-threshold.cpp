
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if (sum >= k * threshold) {
            count++;
        }

        for (int right = k; right < arr.size(); right++) {
            sum += arr[right];
            sum -= arr[right - k];

            if (sum >= k * threshold) {
                count++;
            }
        }

        return count;
    }
};