class Solution {

public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Create an array to track population changes from year 1950 to 2050
        // Size 101 covers index 0 (1950) to 100 (2050)
        int populationChanges[101] = {0};
        
        // Mark the birth and death changes
        for (const auto& log : logs) {
            int birth = log[0];
            int death = log[1];
            
            populationChanges[birth - 1950]++;
            populationChanges[death - 1950]--;
        }
        
        int maxPopulation = 0;
        int currentPopulation = 0;
        int maxYear = 1950;
        
        // Running prefix sum to find the year with the maximum population
        for (int i = 0; i < 101; ++i) {
            currentPopulation += populationChanges[i];
            
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                maxYear = 1950 + i;
            }
        }
        
        return maxYear;
    }
};

     
        
