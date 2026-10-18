class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0;
        
        // Alternate characters until one string runs out
        while (i < word1.length() && j < word2.length()) {
            result += word1[i++];
            result += word2[j++];
        }
        
        // Append any remaining characters from word1
        if (i < word1.length()) {
            result += word1.substr(i);
        }
        
        // Append any remaining characters from word2
        if (j < word2.length()) {
            result += word2.substr(i); // Since i == j at this point, j works too
        }
        
        return result;
    }
};
