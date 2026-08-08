class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        istringstream stringStream(s);
        vector<string> words;
        string word;
        while (stringStream >> word) {
            words.push_back(word);
        }
      
        
        if (pattern.size() != words.size()) {
            return false;
        }
      
       
        unordered_map<char, string> charToWord;  
        unordered_map<string, char> wordToChar;  
        
        for (int i = 0; i < words.size(); ++i) {
            char currentChar = pattern[i];
            string currentWord = words[i];
          
            
            if ((charToWord.count(currentChar) && charToWord[currentChar] != currentWord) || 
                (wordToChar.count(currentWord) && wordToChar[currentWord] != currentChar)) {
                return false;
            }
          
           
            charToWord[currentChar] = currentWord;
            wordToChar[currentWord] = currentChar;
        }
      
        return true;
    }
};
