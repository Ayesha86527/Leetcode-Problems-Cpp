class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int maxlen=0;
        int start=-1;
        for (int i=0;i<s.length();i++){
            if (freq[s[i]]>start){
                start=freq[s[i]];
            }
            freq[s[i]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
    }
};