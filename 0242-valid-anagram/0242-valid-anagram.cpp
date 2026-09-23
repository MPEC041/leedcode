// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//            sort(t.begin(),t.end());
//            for(int i=0;i<=s.size();i++)
//            {
//              for(int j=0;j<=t.size();j++)
//              {
//                 if(s==t)
//                 return true;
//              }
//            }
//            return false;
    

        
//     }
// };
class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Direct comparison
        return s == t;
    }
};
