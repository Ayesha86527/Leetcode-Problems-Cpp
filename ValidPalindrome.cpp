class Solution {
public:
    bool valid(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }
    
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start < end) {

            while (start < end && !valid(s[start])) {
                start++;
            }
            
            while (start < end && !valid(s[end])) {
                end--;
            }
            
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
};