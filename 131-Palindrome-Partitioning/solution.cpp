class Solution {
public:
//回文划分
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        if(s.size() == 0) return res;
        helper(res, s, path, 0);
        return res;
    }
    void helper(vector<vector<string>>& res, string& s, vector<string>& path, int pos){
        if(pos == s.size())
            res.push_back(path);
        for(int i = pos; i < s.size(); i++) {
            if(isPalindrome(s, pos, i)) {
                path.push_back(s.substr(pos, i - pos + 1));
                helper(res, s, path, i + 1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};