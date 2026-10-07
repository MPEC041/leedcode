// class Solution {
// private:
   
//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }

// public:
//     int maxVowels(string s, int k) {
//         int max_vowels = 0;
//         int current_vowels = 0;
        
     
//         for (int i = 0; i < k; i++) {
//             if (isVowel(s[i])) {
//                 current_vowels++;
//             }
//         }
//         max_vowels = current_vowels;
        
       
//         for (int right = k; right < s.length(); right++) {
           
//             if (isVowel(s[right])) {
//                 current_vowels++;
//             }
           
//             if (isVowel(s[right - k])) {
//                 current_vowels--;
//             }
            
            
//             max_vowels = max(max_vowels, current_vowels);
//         }
        
//         return max_vowels;
//     }
// };
    
class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0;
        int count = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            if (isVowel(s[right]))
                count++;

            if (right - left + 1 > k) {
                if (isVowel(s[left]))
                    count--;

                left++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};