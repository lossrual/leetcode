class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        if(s.size() == 0) return res;
        for(int i = 0; i < s.size(); i++) {
            int pos = i;
            if(s[i] == ' ') continue;
            while(s[i] != ' ' && i < s.size()) ++i;
            if(res.size()) res = " " + res;
            res = s.substr(pos, i - pos) + res;
        }
        res = s;
    }
};