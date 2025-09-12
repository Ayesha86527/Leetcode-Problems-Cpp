class Solution {
public:
    string reorderSpaces(string text) {
        int s_count = 0;
        int w_count = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                s_count++;
            }
        }

        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ' && (i == 0 || text[i-1] == ' ')) {
                w_count++;
            }
        }

        int final_space = (w_count > 1 ? s_count / (w_count - 1) : 0);
        int extra_space = (w_count > 1 ? s_count % (w_count - 1) : s_count);

        string res = "";
        string word = "";
        vector<string> words;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ') {
                word += text[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        if (!word.empty()) words.push_back(word);

        for (int i = 0; i < words.size(); i++) {
            res += words[i];
            if (i < words.size() - 1) {
                res.append(final_space, ' ');
            }
        }
        res.append(extra_space, ' ');

        return res;
    }
};