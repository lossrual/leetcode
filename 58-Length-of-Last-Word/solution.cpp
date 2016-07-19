class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        if(s.size() == 0) return 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(isalnum(s[i]) && s[i] != ' ') ++count;
            if(s[i] == ' ' && count) return count;
        }
        return count;
    }
};