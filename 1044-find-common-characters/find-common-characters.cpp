#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        
        std::vector<int> min_freq(26, 1000); 

        
        for (char c : words[0]) {
            min_freq[c - 'a']++;
        }
      
        for (int i = 0; i < 26; ++i) {
            if (min_freq[i] == 1000) min_freq[i] = 0;
            else min_freq[i] -= 1000;
        }

        
        for (size_t i = 1; i < words.size(); ++i) {
            std::vector<int> current_freq(26, 0);
            for (char c : words[i]) {
                current_freq[c - 'a']++;
            }
            
            
            for (int j = 0; j < 26; ++j) {
                min_freq[j] = std::min(min_freq[j], current_freq[j]);
            }
        }

       
        std::vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            while (min_freq[i] > 0) {
                result.push_back(std::string(1, 'a' + i));
                min_freq[i]--;
            }
        }

        return result;
    }
};
