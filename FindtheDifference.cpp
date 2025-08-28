class Solution {
public:
    char findTheDifference(string s, string t) {
        string final=s+t;
        char letter=0;
        for (int i=0;i<final.length();i++){
            letter=letter^final[i];
        }
        return letter;
        
    }
};