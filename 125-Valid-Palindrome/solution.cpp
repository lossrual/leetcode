class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        for(int i = 0, j = s.size() - 1; i <  s.size() && j >= 0; i++, j--){
            while(i < s.size() && !isalnum(s[i])) ++i;
            while(j >= 0 && !isalnum(s[j])) --j;
            if(toupper(s[i]) != toupper(s[j]) && i < s.size() && j >= 0)
                return false;
        }
        return true;
    }
};