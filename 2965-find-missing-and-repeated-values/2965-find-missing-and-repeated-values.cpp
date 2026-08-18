
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        
        int repeated = -1;
       
        vector<bool> visited((n * n) + 1, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int current = grid[i][j];
                sum += current; 
                if (visited[current]) {
                    repeated = current;
                }
                visited[current] = true;
            }
        }

        
        int total_elements = n * n;
        int expected_sum = total_elements * (total_elements + 1) / 2;

       
        int missing = repeated - (sum - expected_sum);

        return {repeated, missing};
    }
};
